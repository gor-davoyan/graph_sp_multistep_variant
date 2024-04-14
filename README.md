# City Travel Planner

City Travel Planner is a C++ program designed to optimize travel plans for visiting multiple destinations within a city. By analyzing the city map and provided destinations, the program determines the best order to visit these destinations, minimizing the total travel distance.

## Features

- **Optimal Destination Order**: Calculates the best order of destinations to minimize total travel distance.
- **Length of Trips**: Provides the lengths of trips between consecutive destinations.
- **Floyd-Warshall Algorithm**: Utilizes the Floyd-Warshall algorithm to find the shortest paths between intersections.
- **Comprehensive Output**: Outputs the optimal travel plan, lengths of trips, and total length of travel.

## Usage

1. **Clone the Repository**: Clone the repository to your local machine.
2. **Build the Project**: Navigate to the project directory and create a build directory. Inside the build directory, run CMake to generate the build files for your platform:
   ```bash
   mkdir build
   cd build
   cmake ..
