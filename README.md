# CS-300-Skyline


The İstanbul skyline problem, often mistakenly called the New York skyline problem, is
the problem of drawing the skyline of a city given a set of buildings of that city. In this
homework you will write a program whose input is a list of the locations and sizes of
buildings, and whose output is a description of the visible skyline, that is, how the city
looks as an outline, when viewed from a distance. For a real-life version of this problem,
go to Vaniköy on the Asian side of the Bosphorus, and, as you sip your tea, contemplate
on how the skyline will look as the sun sets over the European side.
To make things simple, the buildings will be given using just two dimensions, x and y,
rather than three, ignoring the depth value. (Think of x as horizontal and y as vertical.)
Each building will be a rectangle with its base on the x-axis. Thus, a building can be
completely described by giving the x-coordinates of its left and right sides, and the y
coordinate (or height) of its top side. The first line of the input indicates how many
buildings there are in the city, and each succeeding line will indicate the x-coordinate of
the left side of a building followed by the y-coordinate of the top side of the building,
followed by the x-coordinate of the right side of the building. The following is an
example of a valid input to the program:
4
2 50 10
35 20 55
30 60 45
5 75 25
Notice that buildings may overlap. For example, the first building, which spans 2 through
10 on the x-axis, overlaps the fourth building, which spans 5 through 25 on the x-axis. If
the right x-coordinate of a building is the same as the left x-coordinate of another
building, then the two buildings are considered to be side by side (though their heights
may differ!)
The output of this program should be a description of the skyline of the city. The skyline
is the upper outline of the buildings in the city. To be more precise, the skyline is a
function that maps each x-coordinate to the y-coordinate of the tallest building that covers
that x-coordinate. Since all of our buildings are rectangles, this function will be a curve
consisting of horizontal and vertical line segments. Your program should describe the
skyline function by listing each x coordinate at which the height of the skyline changes,
along with the new coordinate of the skyline at that x. Your program should do this in the
direction of increasing x coordinate (i.e., left to right). For example, the following output
describes the skyline of the input above:
0 0
2 50
5 75
25 0
30 60
45 20
55 0
This output indicates that initially the skyline is at height 0 (which may be different if
there is a building starting at 0). At x-coordinate 2, the height of the skyline becomes 50.
The height remains 50 until x-coordinate 5, at which point (because of the fourth
building) it becomes 75. Then, at x-coordinate 25 the height becomes 0, and so forth.
The following figure depicts this instance of the problem where the buildings are shown
with rectangles and the skyline is shown with the think outline.
