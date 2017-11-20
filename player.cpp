#include "player.h"


int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
	
   if(Player* const P = static_cast<Player*>(data)){
		
		P->player_name_ = argv[0];
		P->score_ = atoi(argv[1]);
	}
   

   return 0;
}


Player::Player(): Player("",0){}

Player::Player( std::string pname, size_t score): player_name_(pname), score_(score){}

void Player::createPlayerInfo(){
	
     sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	std::string sql;

	/* Open database*/
	rc = sqlite3_open("scores.db", &db);

	if(rc){
		
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else{
		fprintf(stdout, "Opened database successfully\n");
	}
		
	/*Create SQL statement */

	sql = "CREATE TABLE IF NOT EXISTS Player ("\
		 "Name	TEXT		NOT NULL,"\
		 "Score   INTEGER);"; \
		 
	
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
	
	rc = sqlite3_open("scores.db", &db);
	
	if(rc){
		
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else{
		
		fprintf(stderr, "Opened database successfully\n");
	}	
	/* Create SQL statement */
	
	sql = "INSERT INTO Player(Name, Score)"\
		 " VALUES('"+ player_name_ +"','"+ std::to_string(score_) +"');";

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
	
	Player* data =  new Player();

	/* Open database */
	
	rc = sqlite3_open("scores.db", &db);

	if(rc){
		
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else{
		fprintf(stderr, "Opened database successfully\n");
	}
	
	/* Create SQL statement */
	sql = "SELECT Name, MAX(Score) FROM Player;";

	std::cout <<sql <<std::endl;

	/* Execute SQL statement */

	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);

	if(rc != SQLITE_OK){
		
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else{
		fprintf(stdout, "Operation done successfully\n");
	}
	
	hs_name_ = data->player_name_;
	high_score_ = data->score_;
	
	delete data;
	
	sqlite3_close(db);
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

std::string Player::getHSName() const{

}

size_t Player::getHighScore()const{
    return high_score_;
}
void Player::setHighScore(std::string hsname, size_t hs){
	hs_name_ = hsname;
	high_score_ = hs;
}

int main(){
	Player p;
	std::string hsname;
	int hs = 0;
	p.createPlayerInfo();
	std::string name = "Zules";
	int score1 = 1;
	p.setName(name);
	p.setScore(score1);
	p.insertInfo();
	std::string name2 = "Jsin";
	int score2 = 0;
	p.setName(name2);
	p.setScore(score2);
	p.insertInfo();
	std::string name3 = "Thania";
	int score3 =3;
	p.setName(name3);
	p.setScore(score3);
	p.insertInfo();
	
	
	p.retrieveInfo();
	
	hsname = p.getHSName();
	hs = p.getHighScore();

	std::cout << "High score: " << hsname << " "<< hs <<std::endl;
}

