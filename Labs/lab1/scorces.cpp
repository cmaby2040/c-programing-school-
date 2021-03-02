#include <iostream>
#include <Vector>
#include <string>


int main(){
	int first, second, endPRG, wins=0,draws= 0, losses=0;
	int firstCounter=0, secondCounter=0, hScoreWin=0, hScoreLose=0;
	int hWinFirst=0, hWinSecond=0, hLossFirst=0, hLossSecond=0, counter=0, counter2=0;
	std::string teamName, losingName, winningName;
    bool end = true;
    std::vector<int> v1;
    std::vector<std::string> v2;
	std:: cout << "insert -1 to finish entering games if not enter anything ";
	std:: cin >> endPRG;
	while(end){
		if (endPRG==-1){
		std::cout <<"Wins/Draws/Losses " << wins <<":"  << draws <<":" << losses << std::endl;
		std::cout << "goals: " <<firstCounter <<":" <<secondCounter << std::endl;
		float avgGoals;
		avgGoals=((float)firstCounter)/(wins+draws+losses);
		std::cout << "Average number of goals scored: " << avgGoals << std::endl;
		if (wins==0){
			std::cout << "Highest Win: None" <<std::endl;	
		}else{
			std::cout << "Highest win: " << hWinFirst << ":" << hWinSecond << " "<< winningName << std::endl;
		}	
		if (losses==0){
			std::cout << "Largest Loss: None" <<std::endl;	
		}else{
			std::cout << "Largest Loss: " << hLossFirst << ":" << hLossSecond << " "<< losingName << std::endl;
		}
		
		std::cout << "Games" << std::endl;
		for(std::vector<int>::iterator iter = v1.begin(); iter != v1.end();iter++){
			if(*iter !=-1){
				if (counter%2==0){
				std::cout << *iter << ":";
				counter++;
				}
				else{
				 std::cout << *iter;
				 counter++;	
				}
				if (counter%2==0){
					std::cout << " " << v2[counter2++] << std::endl;
				}
			}	
		}
		return 0;
	
	}		
	else{
		
		std::cout << "What is the first score? ";
		std::cin >> first;
		v1.push_back(first);
		if (first != -1){
			firstCounter+=first;
			std::cout << "What is the second score? ";
			std::cin >> second;
			secondCounter+=second;
			v1.push_back(second);
			std::cout << "What is the team name? ";
			std::cin >> teamName;
			v2.push_back(teamName);
			if (first > second ){
				wins++;
				if((first-second)>hScoreWin){
					hScoreWin= first-second;
					hWinFirst=first;
					hWinSecond= second;
					winningName=teamName;
				}else if((first-second)==hScoreWin){
					if(first>hWinFirst){
						hWinFirst=first;
						hWinSecond= second;	
						winningName=teamName;
					}
				}
			}else if(second==first){
				draws++;
			}else{
				losses++;
				if((second-first)>hScoreLose){
					hScoreLose= second-first;
					hLossFirst=first;
					hLossSecond= second;
					losingName=teamName;
				}else if((second-first)==hScoreLose){
					if(first>hLossFirst){
						hLossFirst=first;
						hLossSecond= second;
						losingName=teamName;	
					}
				}
			}
			
		}else {
			end=false;
		}
	
	}
}
}

