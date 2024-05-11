This is english version of project description, polish version available [here](readme-polish.md)

# jakdojade
**Author of the instruction:** Krzysztof Ocetkiewicz

**Description**
A rectangular map divided into squares is given. Each field on the map can be empty (impassable), be part of a road (passable in both directions), or be a city (passable like a road). The name of each city is given on the map, and each letter occupies one field (the field with the letter is impassable). Moving through one field takes one minute. We can only move between fields adjacent by sides. Additionally, selected cities are connected by one-way air connections. The name of a city will be adjacent (by side or corner) to the city with the first or last letter of the name.
The name will be unambiguously assigned to the city. There will be no number or letter before or after the name of the city (if there is such a field).

**Implementation notes:**

- Standard string class and other standard library containers cannot be used.
- You can use C++ elements such as classes, references, etc.
- One can implement their own string class.
- Code readability is important, and comments (which are of course allowed) do not necessarily ensure it.
- Smartpointers from standard library are forbidden, but you can still implement your own smartpointer class.
- Please remember to free memory when deleting elements of the implemented data structures.

**Examples:**

*This can be:*

```
*GDANSK....OPOLE....RUMIA
...*GDYNIA......*....*...
*SOPOT.............*....*
...PUCK*.*KRAKOW.REDA.HEL
```

*This is incorrect:*

```
**GDANSK..........OPOLE.
..........*GDYNIA*......
*SOPOTHEL...............
........*..REDA.*PUCK*..
```

*It is possible to arrive from point A to B:*

```
..................
A*####...#####*B..
.....#.C.#........
.....##*##........

......
.A**B.
......
```

*It is not possible to arrive from point A to B:*

```
....##*B
A*##....

....##*B
A*#*C...

....*....
A*##C##*B
```

**Input:**
The first line of input will contain the dimensions of the map: width w and height h. The next h lines (each containing w characters) will describe the map. Each character in the description is a dot (.) representing an empty field, a cross (#) representing a road, an asterisk (*) representing a city, or a letter or number that is part of the city name.
The next line will contain a single integer k - the number of flight connections. The next k lines will describe the connections in the format source destination time, where source is the name of the starting city, destination is the name of the destination city, and time is the flight time in minutes. The next line will contain a single integer q - the number of queries. Each query will appear on a separate line and will have the format source destination type. This is a query for the shortest travel time from the source city to the destination city. If the type is zero, the query is only for the time. If the type is one, the route should also be provided. 

**Output:**
For each query, output one line. At the beginning of the line should be the number representing the shortest travel time between the cities. If the query has a type of one, all intermediate cities (excluding the starting and ending cities) should also be listed in the order they were visited, separated by spaces.

**Tests:**
1. example
2. minimum
3. label reading correctness
4. correctness
5. simple test on a grid
6. small fan
7. small path
8. small complete graph
9. large map, few cities
10. large map, few cities
11. fan, array implementation may not fit in time
12. spiral, recursion implementation of search overflows the stack
13. long path, array implementation may not fit in time
14. many edges

**Example:**

*Input:*
```
20 20
.........GDANSK.....
........*...........
........#...........
........#...........
*##################.
#SZCZECIN.........#.
#.................#.
##................#.
.############*#####.
.#...WARSZAWA.......
.#..................
.#############......
.#...........#......
.#..WROCLAW.##......
.#..*.......*.......
.####.......#KIELCE.
......*##.#########.
.OPOLE..#.*.......#.
........#.KRAKOW..#.
........###########.
0
3
KIELCE KRAKOW 0
KRAKOW GDANSK 0
KRAKOW GDANSK 1
```

*Output:*
```
5
40
40 KIELCE SZCZECIN
```
