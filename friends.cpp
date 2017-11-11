
#include "friends.h"


Friends::Friends(): Friends(0,"",""){}

Friends::Friends(size_t id, std::string name, std::string picurl) : id_(id), name_(name), picurl_(picurl){}

int callback(void* data, int argc, char** argv, char** azColName){

	struct tm blob;	
	
	for(int i = 0; i < argc; i++){
		
		if(!strcmp(azColName[i], "PICS"))
		{  //HAndle Blob data
			memcpy(&blob, argv[i], sizeof(struct tm));
			std::cout << "Retrieved from blob: " << "blob.tm_" <<std::endl;
		}
		else{	//All other database columns
		std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}

void Friends::setId(size_t id){
	id_= id;
}

size_t Friends::getId(){
	return id_;
}

void Friends::setNames(std::string fname){
    
    name_ = fname;
}

std::string Friends::getNames() const{

    return name_;
}

void Friends::setPicUrls(std::string pic){
	
	picurl_ = pic;
}

std::string Friends::getPicUrls() const{

    return picurl_;
}

std::string Friends::genRandom(){

    return friends[rand() % stringLength];
}

bool Friends::compareNames(std::string random, std::string guess){
    
    std::transform(random.begin(), random.end(), random.begin(), ::toupper);
    std::transform(guess.begin(),guess.end(), guess.begin(), ::toupper);
    
    
    if(guess == random){
        std::cout << "Yep. Thats right." << std::endl;
        return true;
    }
    else{
        std::cout << "Nope. Thats not right." <<std::endl;
        return false;
    }
    
}

void Friends::insertBlob(){

	sqlite3* db;
	char* zErrMsg = 0;
	
	time_t tt = 0;
	time_t now = time(&tt);		// seconds since the Epoch
	struct tm* blob = gmtime(&now);  //Create the blob to store in the database

	std::cout <<"Stored: "<< "blob->tm_"<< std::endl;
	std::cout << std::endl;

	int rc = sqlite3_open("friends.db", &db);
	if(rc){
		std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
		exit(1);
	}
	
	//Insert blob data into database

	std::string zSql = "INSERT INTO Friends(ID,NAME,PIC) VALUES('"+ std::to_string(id_) +"','" + name_ +"', ?);";
	sqlite3_stmt* ppStmt;
	const char** pzTail;

	if( sqlite3_prepare_v2(db, zSql.c_str(), sizeof(zSql)+1, &ppStmt, pzTail) != SQLITE_OK)
	{
		std::cerr<<"db error: " << sqlite3_errmsg(db) <<std::endl;
		sqlite3_close(db);
		exit(1);
	}
	
	if(ppStmt){
	
	// For Blob column bind 
	sqlite3_bind_blob(ppStmt, id_, blob, sizeof(struct tm), SQLITE_TRANSIENT);
	sqlite3_step(ppStmt);
	sqlite3_finalize(ppStmt);
	sqlite3_exec(db, "COMMIT", NULL, NULL, NULL);
	
	}
	else{
		std::cerr<< "Error: ppStmt is NULL" << std::endl;
		sqlite3_close(db);
		exit(1);
	}
	// CLose database
	
	sqlite3_close(db);
}
	
void Friends::retrieveBlob(){

	sqlite3* db;
	char* zErrMsg = 0;

	int rc = sqlite3_open("friends.db", &db);
	if(rc){
		std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
		exit(1);
	}
	
	// Select rows from database

	rc = sqlite3_exec(db, "SELECT * FROM Friends", callback, 0, &zErrMsg);
	if( rc != SQLITE_OK){
		
		std::cerr << "SQL error: " << zErrMsg << std::endl;
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		exit(1);
	}

	sqlite3_exec(db, "END", NULL, NULL, NULL);
	
	sqlite3_close(db);
}

void Friends::deleteBlob(){
	
	sqlite3* db;
	char* zErrMsg = 0;

	int rc = sqlite3_open("friends.db", &db);
	if(rc){
		std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
		exit(1);
	}
	
	// Select rows from database

	rc = sqlite3_exec(db, "DELETE FROM Friends", callback, 0, &zErrMsg);
	if( rc != SQLITE_OK){
		
		std::cerr << "SQL error: " << zErrMsg << std::endl;
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		exit(1);
	}

	sqlite3_exec(db, "END", NULL, NULL, NULL);
	
	sqlite3_close(db);
}


