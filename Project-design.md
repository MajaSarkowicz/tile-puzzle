# Designing the structure of the project at a high level

## Top level functionalities

### Board

- Display the board

- Update the state of the board after capturing valid command

- Prevent going out of bounds of the board

  - keep the dimentions constant,

  - disable movement out of bounds

- Display an individual tile

- Randomize the starting state

- Slide tiles

- Determine if win condition reached

### User

- Get commands from user

- Handle invalid input

- Allow the user to quit before winning

## Implementation - namespaces, classes and main()

### Primary class/namespace/main

#### `class Board`

- Display the game board

- Randomize the starting state

- Slide tiles

- Determine if win condition reached

**Members:**

- `2d array of tile`

---

#### `function main`

- Main game loop logic

- Allow user to quit before winning

---

#### `class Tile`

Display an individual tile

**Members:**

- `int m_val{}`

---

#### `namespace UserInput`

- Get value from user

- Handle bad stream input

### Helper classes / capabilities

- Printing out to the console <=> overloading stream operators

- Assesing relations between tiles <=> overloading relation operators