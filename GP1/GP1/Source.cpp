#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queueAsArray.h"
#include "queueADT.h"
using namespace std;

// Function prototypes
void simulateAirport(int landingTime, int takeoffTime, double landingProbability, double takeoffProbability, int maxWaitTime, int simulationTime);
bool isPlaneArrived(double probability);

int main()
{
    // Variables to store user inputs for simulation parameters
    int landingTime, takeoffTime, maxWaitTime, simulationTime;
    double landingProbability, takeoffProbability;

    // Collecting parameters for the simulation from the user
    cout << "Enter the amount of time needed for one plane to land (in minutes): ";
    cin >> landingTime;
    cout << "Enter the amount of time needed for one plane to take off (in minutes): ";
    cin >> takeoffTime;
    cout << "Enter the average amount of time between the arrival of planes to the landing queue (in minutes): ";
    cin >> landingProbability;
    landingProbability = 1.0 / landingProbability; // Convert to probability per minute
    cout << "Enter the average amount of time between the arrival of planes to the takeoff queue (in minutes): ";
    cin >> takeoffProbability;
    takeoffProbability = 1.0 / takeoffProbability; // Convert to probability per minute
    cout << "Enter the maximum amount of time that a plane can stay in the landing queue without running out of fuel and crashing (in minutes): ";
    cin >> maxWaitTime;
    cout << "Enter the total length of time to be simulated (in minutes): ";
    cin >> simulationTime;

    // Starting the simulation with the provided parameters
    simulateAirport(landingTime, takeoffTime, landingProbability, takeoffProbability, maxWaitTime, simulationTime);
    return 0;
}

// Function to simulate airport operations including landing and takeoff
void simulateAirport(int landingTime, int takeoffTime, double landingProbability, double takeoffProbability, int maxWaitTime, int simulationTime)
{
    // Initializing queues for planes waiting to land and take off
    queueType<int> landingQueue, takeoffQueue;
    // Variables to track simulation state
    int currTime = 0, landingCount = 0, takeoffCount = 0, crashCount = 0;
    int totalLandingWait = 0, totalTakeoffWait = 0;

    srand(time(NULL)); // Seed the random number generator for plane arrival simulation

    // Main simulation loop
    while (currTime < simulationTime)
    {
        // Check and enqueue planes arriving for landing
        if (isPlaneArrived(landingProbability))
        {
            landingQueue.addQueue(currTime);
        }
        // Check and enqueue planes arriving for takeoff
        if (isPlaneArrived(takeoffProbability))
        {
            takeoffQueue.addQueue(currTime);
        }

        // Process landing if there are planes in the landing queue
        if (!landingQueue.isEmptyQueue())
        {
            int planeArrivalTime = landingQueue.front();
            int waitTime = currTime - planeArrivalTime;
            if (waitTime > maxWaitTime) {
                crashCount++;
                landingQueue.deleteQueue(); // Remove crashed plane from queue
                continue; // Skip further processing for this cycle
            }
            // Simulate plane landing
            currTime += landingTime; // Increment current time by the landing duration
            totalLandingWait += waitTime; // Accumulate total wait time for landing
            landingQueue.deleteQueue(); // Remove the plane from the landing queue
            landingCount++; // Increment the count of landed planes
        }
        // Otherwise, process takeoff if there are planes in the takeoff queue
        else if (!takeoffQueue.isEmptyQueue())
        {
            // Simulate plane takeoff
            currTime += takeoffTime; // Increment current time by the takeoff duration
            int planeArrivalTime = takeoffQueue.front();
            totalTakeoffWait += currTime - planeArrivalTime - takeoffTime; // Accumulate total wait time for takeoff
            takeoffQueue.deleteQueue(); // Remove the plane from the takeoff queue
            takeoffCount++; // Increment the count of planes that took off
        }
        else
        {
            // Increment time if no actions occurred
            currTime++;
        }
    }

    // Output the simulation results
    cout << "Number of planes that took off: " << takeoffCount << endl;
    cout << "Number of planes that landed: " << landingCount << endl;
    cout << "Number of planes that crashed: " << crashCount << endl;
    cout << "Average wait time for landing: " << ((landingCount > 0) ? (double)totalLandingWait / landingCount : 0) << " minutes" << endl;
    cout << "Average wait time for takeoff: " << ((takeoffCount > 0) ? (double)totalTakeoffWait / takeoffCount : 0) << " minutes" << endl;
}

// Function to simulate plane arrival based on given probability
bool isPlaneArrived(double probability)
{
    return (rand() / (RAND_MAX + 1.0)) < probability;
}
