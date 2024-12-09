/* A solar marketing specialist travels from Riverside to Moreno Valley, then to Perris and Hemet to market solar packages to homeowners. The travel route is shown below:
1.If the marketing specialist begins the trip from home in Riverside, determine the variations of the trip to the noted cities that he must take to market the solar products. 
2. Determine shortest path, and the most low-cost trips for the marketing specialist.
3. Create a C++ program to provide the representation of the trips, low-cost and shortest paths, including matrices, adjacencies.
4. Provide documentation that explains solution and programming approaches. */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Route{
    string city1, city2, city3, city4, destination;
    int distance; 
};

struct Edge {
    string src, dest;
    int weight;
};

bool comparison(string T1, string T2);
void printRoute(vector<Route> &routeOptions, int size);
void printShortRoute(vector<Route> &routeOptions, int size);
void printLongRoute(vector<Route> &routeOptions, int size);
void printLowCostRoute(vector<Route> &routeOptions, int size);

int main()
{
    vector<string> trips = {"Moreno Valley", "Perris", "Hemet" };

    Edge edges[] = {
        {"Riverside", "Hemet", 33},
        {"Riverside", "Perris", 24},
        {"Riverside", "Moreno Valley", 16},
        {"Hemet", "Moreno Valley", 26},
        {"Perris", "Hemet", 30},
        {"Perris", "Moreno Valley", 18}        
    };

    int n = trips.size(); 
    int m = sizeof(edges) / sizeof(edges[0]); 
    int j=0; 
    Route path; 
    vector<string> cityTrips; 
    vector<Route> routeOptions; 

    sort(trips.begin(), trips.end(), comparison); 

    do{
        int distance=0;             
        for(int i=0; i<n; i++){
            cityTrips.push_back(trips[i]); 

        } 

        path.city1 = "Riverside"; 
        path.destination = "Riverside";
        path.city2 = cityTrips[0]; 
        path.city3 = cityTrips[1];
        path.city4 = cityTrips[2];

        for(int k=0; k<m; k++){
            if(edges[k].src == "Riverside" && path.city2==edges[k].dest){
                distance += edges[k].weight;
            }

            if((path.city2 == edges[k].src && path.city3==edges[k].dest)
                    || (path.city3==edges[k].src && path.city2==edges[k].dest)){
                distance += edges[k].weight;
            }

            if((path.city3==edges[k].src && path.city4==edges[k].dest)
                    || (path.city4==edges[k].src && path.city3==edges[k].dest)){
                distance += edges[k].weight;   
            }

            if(edges[k].src == "Riverside" && path.city4 ==edges[k].dest ){
                distance += edges[k].weight;
            }
        }       

        path.distance=distance;       
      routeOptions.push_back(path);
        cityTrips.clear();
        path={};
        j++;          
    }while(next_permutation(trips.begin(), trips.end()));

    sort(routeOptions.begin(), routeOptions.end(), [](Route path1, Route path2){
        return path1.distance < path2.distance;
    }
    );

    while(true){
        int choice;
        cout << "Riverside ";
        cout << "Inland Empire Search market maps:" << endl;
        cout << "1. Routes: " << endl;
        cout << "2. Shortest path: " << endl;
        cout << "3. Lowest_cost path: " << endl;
        cout << "4. Longest path: " << endl;
        cout << "5. exit" << endl;
        cin >> choice;

        if(choice == 1)
            printRoute(routeOptions, j);

        else if(choice == 2)
              printShortRoute(routeOptions, j);

        else if(choice == 3)
              printLowCostRoute(routeOptions, j);

        else if(choice == 4)
              printLongRoute(routeOptions, j);

        else if(choice == 5)
            exit(0);

        else{
            cout << "The option you have chosen does not exist, please select another option 1-5." << endl;
            cin >> choice;
        }
    }
    return 0;
}


bool comparison(string T1, string T2)
{
    return (T1 < T2);
}

void printRoute(vector<Route> &routeOptions, int size){
    for(int i=0; i<routeOptions.size(); i++){
        cout << routeOptions[i].city1 << " -> " << routeOptions[i].city2 << " -> " << routeOptions[i].city3 << " -> " <<
          routeOptions[i].city4 << " -> " << routeOptions[i].destination << endl;
        cout << "Route " << i+1 << " mills : " << routeOptions[i].distance << "\n" << endl;           
    }
}


void printShortRoute(vector<Route> &routeOptions, int size){
    int min; 
    for (int i=1; i<size; i++){
        if(routeOptions[0].distance == routeOptions[i].distance)
            min = i;
    }

    cout << "\nThe shortest path is: \n";
    cout << routeOptions[0].city1 << " -> " << routeOptions[0].city2 << " -> " << routeOptions[0].city3 << " -> " <<
      routeOptions[0].city4 << " -> " << routeOptions[0].destination << "\nThe distance is " <<
      routeOptions[0].distance << endl;
    cout << "Or\n";
    cout << routeOptions[min].city1 << " -> " << routeOptions[min].city2 << " -> " << routeOptions[min].city3 << " -> " <<
      routeOptions[min].city4 << " -> " << routeOptions[min].destination << "\nThe distance is " <<
      routeOptions[min].distance << "\n" << endl;
}

void printLowCostRoute(vector<Route> &routeOptions, int size){    
    int min; 
    for (int i=1; i<size; i++){
        if(routeOptions[0].distance == routeOptions[i].distance)
            min = i;
    }

    cout << "\nThe Lowest_cost path is: \n";
    cout << routeOptions[0].city1 << " -> " << routeOptions[0].city2 << " -> " << routeOptions[0].city3 << " -> " <<
      routeOptions[0].city4 << " -> " << routeOptions[0].destination << "\nThe distance is " <<
      routeOptions[0].distance << endl;
    cout << "Or\n";
    cout << routeOptions[min].city1 << " -> " << routeOptions[min].city2 << " -> " << routeOptions[min].city3 << " -> " <<
      routeOptions[min].city4 << " -> " << routeOptions[min].destination << "\nThe distance is " <<
      routeOptions[min].distance << "\n" << endl;
}

void printLongRoute(vector<Route> &routeOptions, int size){   
    int k=size-1;
    int max;
    for (int i=0; i<k; i++){
        if(routeOptions[k].distance == routeOptions[i].distance)
            max = i;
    }

    cout << "\nThe Longest path is: \n";
    cout << routeOptions[k].city1 << " -> " << routeOptions[k].city2 << " -> " << routeOptions[k].city3 << " -> " <<
      routeOptions[k].city4 << " -> " << routeOptions[k].destination << "\nThe distance is " <<
      routeOptions[k].distance << endl;
    cout << "Or\n";
    cout << routeOptions[max].city1 << " -> " << routeOptions[max].city2 << " -> " << routeOptions[max].city3 << " -> " <<
      routeOptions[max].city4 << " -> " << routeOptions[max].destination << "\nThe distance is " <<
      routeOptions[max].distance << "\n" << endl;
}