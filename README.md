<H1> COP3530 - Project 2 - Delayradar 24 </h1>

Flight delays are a huge cause of stress for passengers and often lead to missed connections or extra travel costs. While the flight data and delay records are public, they are found in giant, cluttered lists with endless data that makes it almost unreadable. This program transforms the raw data that’s hardly usable for regular people, and sorts the data into a useful list to help with decision making when booking flights. By finding the most and least commonly delayed airports, users can determine which airports should be avoided, which are ideal, and which ones they might want to add an extra cushion of time to their connections for.

The goal of this project is to create a program that can take a massive dataset of flight records (in this scenario we are using a CSV file with US flight records from early 2024) and sort the airports by their average delay. To do this, we need to process all of the flight records from the CSV file (over 1 million rows of data in our sample file) and then aggregate and average out the delays of each origin airport. Then the average delays of each airport must be sorted for the user to be able to see the most and least delayed airports. This program allows users to use a menu to interact with the sorted data and see a historical record of the delays at every major airport.

<H2> How to Run <H2>

1. Clone the repository
2. Compile the code with "make" in the terminal (mac), "mingw32-make" (win)
3. Run the executable with "./delayradar.exe" (mac), ".\delayradar.exe" (win)
