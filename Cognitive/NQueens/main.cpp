#include "state.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class QueensState: private State{
    public:
        /**
         * This function allows the user to set the number of queens of the problem.
         * It should be passed as a pointer to an int variable with the desired value.
         */
        static void setParameters(void *parameters);

        /**
         * This function returns the initial state for the queens problem. An empty board
         */
        static State* getInitialState();

        /**
         * Destructor
         */
        virtual ~QueensState();
};

int main(){

	int numQueens;
	cout<<"Write the number of queens in the board: ";
	cin>>numQueens;

	QueensState::setParameters(&numQueens);

	State *initialState=QueensState::getInitialState();

    stack <State*> frontier;
    vector <State*> *Successors;
    bool objective=false;
    frontier.push(initialState);
    while((frontier.empty())!=1 && objective== false){
        objective=frontier.top()->isObjective();
        if(objective==true){
            cout<<"Solucion state:\n";
            frontier.top()->print();
        }
        else{
            cout<<"State with no solution:\n";
            Successors=frontier.top()->getSuccessors();
            frontier.pop();
        }
        for(int i=0; i<Successors->size(); i++){
            frontier.push(Successors->at(i));
        }
    }
    delete Successors;

    if(frontier.empty())
		cout<<"There is no solution for "<<numQueens<<" queens"<<endl;
    
	return 0;
    
}
