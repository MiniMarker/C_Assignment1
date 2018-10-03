# Ascii art merger

## How to run the program
1. Clone this repo
2. In folder compile using:
  * `gcc program.c -o program`
3. Run the program using:
  * `./program <param>`
  * Only 'wolf' and 'mickey' are allowed params

## Task
The folders contain two different types of ascii art drawings. These folders contain files named “part_x_y_name.txt” these are 30x30 character parts of ASCII-drawings. That is, the asci-art is split into 30 by 30 squares of characters, and need to be puzzled together.

To accomplsh the merge of the files i need to read one row at the time and append a "\n" at the end of every merged row. When i'm done with the first row of 3xfiles i need to move on to the next row of files until all rows are read.

### Wolf:
The Wolf constists of a grid of 3x5 files.
The grid below represents files in this format:
 - part_x_y_wolf.txt
 
| Column 1 | Column 2 | Column 3 |
| -------- |:--------:| --------:|
| 0,0      | 1,0      | 2,0      |
| 0,1      | 1,1      | 2,1      |
| 0,2      | 1,2      | 2,2      |
| 0,3      | 1,3      | 2,3      |
| 0,4      | 1,4      | 2,4      |

0,0 - 1,0 - 2,0<br/><br/>
0,1 - 1,1 - 2,1<br/><br/>
0,2 - 1,2 - 2,2<br/><br/>
0,3 - 1,3 - 2,3<br/><br/>
0,4 - 1,4 - 2,4<br/><br/>

### Mickey:
The Mickey constists of a grid of 3x2 files.
The grid below represents files in this format:
 - part_x_y_mickey.txt

0,0 - 1,0 - 2,0<br/><br/>
0,1 - 1,1 - 2,1<br/><br/>
