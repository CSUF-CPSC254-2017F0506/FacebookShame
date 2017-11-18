#include "player.h"


int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
	
   if(Player* const P = static_cast<Player*>(data)){
		
		P->player_id_ = atoi(argv[0]);
		P->player_name_ = argv[1];
		P->score_ = atoi(argv[2]);
	}
   

   return 0;
}


Player::Player(): Player(0,"",0){}

Player::Player( size_t pid, std::string pname, size_t score): player_id_(pid), player_name_(pname), score_(score){}

void Player::createPlayerInfo(){
	
     sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	std::string sql;

	/* Open database*/
	rc = sqlite3_open("pscore.db", &db);

	if(rc){
		
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else{
		fprintf(stdout, "Opened database successfully\n");
	}
		
	/*Create SQL statement */

	sql = "CREATE TABLE IF NOT EXISTS Player ("\
		 "ID	 TEXT PRIMARY KEY NOT NULL UNIQUE,"\
		 "NAME   TEXT	 NOT NULL);"; \
		 
	
	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
	
	if(rc != SQLITE_OK){

	fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else{

		fprintf(stdout, "Table created successfully\n");
	}

	sql = "CREATE TABLE IF NOT EXISTS Scores("\
		 "PID TEXT PRIMARY KEY NOT NULL,"\
		 "SCORE INTEGER,"
		 "FOREIGN KEY (PID) REFERENCES Players(ID));";\

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
	
	if(rc != SQLITE_OK){

	fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else{

		fprintf(stdout, "Table created successfully\n");
	}

	sqlite3_close(db);
}

void Player::insertInfo(){

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	std::string sql;

	/* Open dtabase */
	
	rc = sqlite3_open("pscore.db", &db);
	
	if(rc){
		
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else{
		
		fprintf(stderr, "Opened database successfully\n");
	}	
	/* Create SQL statement */
	
	sql = "INSERT INTO Player(ID,NAME)"\
		 " VALUES("+ std::to_string(player_id_) +",'"+ player_name_ +"');";

	/* Execute SQL statement */
	
	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

	if(rc != SQLITE_OK ){

		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else{

		fprintf(stdout, "Records created successfully\n");
	}

	sql = "INSERT INTO Scores(PID,SCORE)"\
		 " VALUES("+ std::to_string(player_id_) +","+ std::to_string(score_) +");";

	/* Execute SQL statement */
	
	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

	if(rc != SQLITE_OK ){

		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else{

		fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);
}

void Player::retrieveInfo(){

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	std::string sql;
	char* data = 0;

	/* Open database */
	
	rc = sqlite3_open("pscore.db", &db);

	if(rc){
		
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else{
		fprintf(stderr, "Opened database successfully\n");
	}
	
	/* Create SQL statement */
	sql = "SELECT * FROM Player"
		 " WHERE ID LIKE \" '"+ std::to_string(player_id_) +"' \";";
	

	/* Execute SQL statement */

	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);

	if(rc != SQLITE_OK){
		
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else{
		fprintf(stdout, "Operation done successfully\n");
	}
	sqlite3_close(db);
}

void Player::setId(size_t id){
	
	player_id_ = id;
}

size_t Player::getId() const{
	
	return player_id_;
}

void Player::setName(std::string pn){
    
	player_name_ = pn;
}

std::string Player::getName() const{
    
    return player_name_;
}

void Player::setScore(size_t s){
    score_ = s;
}

size_t Player::getScore() const {
    return score_;
}

void Player::setHighScore(size_t hs){
   
	high_score_ = hs;
}

size_t Player::getHighScore()const{
    return high_score_;
}

int main(){
	Player p;
	p.createPlayerInfo();
	
	size_t id = 13579;
	p.setId(id);
	std::string name = "Zules";
	p.setName(name);

	size_t score = 0;
	p.setScore(score);
	
	p.insertInfo();
}
