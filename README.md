<p align="center"><i>This project has been created as part of the 42 curriculum by lde-san- & rdeimaos</i></p>

<h1 align="center">🍃🧿 Cub3D - The Verdant Veil 🧿🍃</h1>
<p align="center"><b><em>Sometimes courage and wisdom, can come in the smallest package.</em></b></p>

---

## 🎮 Description
Cub3D is an homage to the legendary Wolfenstein 3D. The project explores the mathematical foundations of early 3D gaming to create a first-person raycasting engine completely in C. At its core, the project focuses on map parsing, texture rendering, event handling, and building a simple game loop. The resulting program is capable of rendering walls with the selected textures, scaling them dynamically based on their distance from the player to create a realistic 3D perspective.


## ⚙️ Instructions

The provided Makefile includes three primary compilation rules:

### 🛠️ Compilation

- **`make`** : Compiles the standard **"`cub3D`"** binary, fulfilling the mandatory requirements of the project.

```bash
make
```

- **`make bonus`** : Compiles the **"`cub3D`"** binary, with some additional features specified in the project's bonus section.

```bash
make bonus
```

- **`make showcase`** : Compiles the **"`cub3D`"** binary, with the additional features from the bonus section, and executes a shell script **"`showcase.sh`"**. that automatically iterates through four custom maps designed to explore the engine's capabilities.

```bash
make showcase
```
## 🛠️ Running the Game

Completing any of the compilation steps above generates a **"`cub3D`"** binary. You can run it by passing the path to a scene file as an argument:

```bash
./cub3D ./maps/scene_n.cub
```

Furthermore, if you compiled using the **`make showcase`** rule, you can execute the generated **"`showcase.sh`"** shell script directly.

```bash
./showcase.sh
```

Alternatively, you can pass a number **`n`** as an argument to start the script from a specific scene:

```bash
./showcase.sh n
```

><br>
>The scene file must fulfill specific conditions outlined in the project subject. This file, in short, is a text file with the *.cub* extension, that the engine interprets to build the 3D environment. Below is an example of a valid scene file:
>
>```text
>NO ./path_to_the_north-facing_texture
>SO ./path_to_the_south-facing_texture
>WE ./path_to_the_west-facing_texture
>EA ./path_to_the_east-facing_texture
>
>F 0,0,0
>C 225,225,225
>
>11111
>10N01
>11111
>```
>The engine is designed to validate this information strictly. However, elements can be arranged in any other and even include spaces in the middle as long as the following conditions are met:
>
> - The *map* grid (The region with ones, zeroes and the player position), must be the last element in the file.
> - The *Identifiers* (*NO*, *SO*, *WE*, *EA*, *F*, *C*), are exacly as shown in the example. For example, for the identifier "NO", variations like "N", "N   O" or "no", will invalidate the scene.
> - Texture paths must not be separated by spaces (unless the directory or file name explicitly contains them).
> - Color values must fall within the valid range (0 - 255). These colors should be defined with the typical RGB format, however, they can have any number or white spaces around or in between the values.
>
> **This information will be interpreted as follows:**
>
> #### 🎬 Scene Identifiers
>
> - **`NO`** :	This *Identifier* Marks the line where the **./path_to_the_north-facing_texture** is stored.
> - **`SO`** :	This *Identifier* Marks the line where the **./path_to_the_south-facing_texture** is stored.
> - **`WE`** :	This *Identifier* Marks the line where the **./path_to_the_west-facing_texture** is stored.
> - **`EA`** :	This *Identifier* Marks the line where the **./path_to_the_east-facing_texture** is stored.
> - **`F`** :	This *Identifier* Marks the line where the color for the **floor** is defined.
> - **`C`** :	This *Identifier* Marks the line where the color for the **ceiling** is defined.
>
> #### 🗺️ Map Format
> The characters within the map grid are interpreted as follows:
>
> - **`[1]`**	Wall.
> - **`[0]`**	Empty space.
> - **`[N]`**	The Player's starting position. Facing *North*.
> - **`[S]`**	The Player's starting position. Facing *South*.
> - **`[W]`**	The Player's starting position. Facing *West*.
> - **`[E]`**	The Player's starting position. Facing *East*.
>
>The map can have any shape, and it can be separated by blank rows or columns, as long as all described regions are completely surrounded by walls, and the spaces are constructed from `' '` characters *(ASCII 32)*.
>
> The map must include exactly one starting position for the player. This position will be marked by a character *(N, S, W, or E)*, which defines *"where"* the player will be facing at the start.
>
> The engine analyzes accessible regions. If there are remote areas or inaccessible rooms defined in the map, they will not be rendered.
<br></br>
---

### 🎮 Controls
- **`WASD`**				→	*Move the Player.*
- **`Arrow Key Left`**		→	*Rotate point of view Left.*
- **`Arrow Key Right`**		→	*Rotate point of view Right.*
- **`ESC`**					→	*Exit game.*
- **`Window Close Button`**	→	*Exit game.*
<br></br>
---

## 🧠 Technical Overview

- Language: **C**

- Graphics API: **MiniLibX (mlx)**

	- **DDA (Digital Differential Analysis):** Core raycasting algorithm used to detect wall intersections.
	- **Camera Plane:** Perpendicular distance calculation to prevent Euclidean "fisheye" distortion.
	- **1D Affine Texture Mapping:** Dynamically scales wall textures based on distance and perspective.
	- **Vector-Based Camera Logic:** Calculates smooth player movement and point-of-view rotation.
	- **Bresenham's Line Algorithm:** Ensures efficient line drawing.
	- **Direct Buffer Rendering:** Bypasses standard grid-drawing by pushing pixels directly to the image data buffer for maximum performance.
	- **Dynamic 2D Camera:** Minimap viewport offset system for rendering massive maps.
	- **Real-Time Sprite Flipping:** Mathematically inverts texture byte-reading to face moving directions without requiring duplicated image assets.
	- **Event Handling:** Fluid window management and synchronous keypress listening.
	- **Map Parsing & Validation:** Strict error-checking and flood-fill validation to refine accessible areas.
	- **Resource Management:** Bulletproof heap allocation and memory cleanup *(because leaks, am I right?)*.
---


## 📚 Resources

- General Documentation:
	- 👉 [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)

- Exploring the math behind Raycasting:
	- 👉 [Ray Casting with DDA. <i>by: javidx9</i>](https://www.youtube.com/watch?v=NbSee-XM7WA&t=669s)

- Calculating Wall Height:
	- 👉 [Raycasting in C. <i>by: Beqa Tvildiani</i>](https://www.youtube.com/watch?v=G9i78WoBBIU)

- Demystifying the Engine:
	- 👉 [Make Your Own Raycaster. <i>by: 3DSage</i>](https://www.youtube.com/watch?v=gYRrGTC7GtA&t=4s)

- Re-Learning Minilibx:
	- 👉 [42 Docs (Unofficial Page). <i>by: harm-smits</i>](https://harm-smits.github.io/42docs/libs/minilibx)
	- 👉 [Previous Project using Minilibx. <i>by: Luis "Mapache" Torcate</i>](https://github.com/Raccoonatic/Glutto-The-Fox/)
- Drawing lines:
  - 👉 [Bresenham's Line Algorithm. <i>by: NoBS Code</i>](https://www.youtube.com/watch?v=CceepU1vIKo)

- Coffee:
	- 👉 ☕.

- Certified [42](https://42.fr/en/network-42/) methodology:
	- 👉 Trial and Error.
	> 🦝 *Break it. Fix it. Make it better.* <br>✨ *Repeat until enlightenment (or burnout). 💥*


 - Focus Boost:<br>
	- [Background Noise](https://www.youtube.com/watch?v=kN-iEJ3Sbsc&list=PLcL9r1K3TSwpOVyQKP1MruSuY-NS99iQY)
	- [Foreground Noise](https://open.spotify.com/playlist/5O5q1xG6hNt7NDA8tmT2KJ?si=14d27a3440ee461b&pt=2d7cc61b518abad19be28b2c99cf7bd6)

## 🤖 AI Usage

AI was used as a **supporting tool**, mainly for:

 - 📘 General documentation lookup *(e.g. signals, system behavior)*
 - 🔍 Code reviewing and Critiquing. *(With unnecesary sass)*
 - 💣 Preventing unnecessary compile attempts *(a.k.a. “yes, you forgot a semicolon again”)*
 - 🧮 Explaining Math *(Don't trust us with a long division)*

---

## 🚨 Other Makefile Utilities

```bash
make mlx_dependencies
```
> Installs system dependencies required by MiniLibX to resolve compilation issues. **Requires sudo access**.

```bash
make clean
```
> Removes the object files created during compilation.

```bash
make fclean
```
> Runs **`make clean`** and removes the compiled **`cub3D`** binary.

```bash
make re
```
> Runs **`make fclean`** and recompiles the standard **`cub3D`** binary.

```bash
make rebon
```
> Runs **`make fclean`** and recompiles the **`cub3D`** binary with the bonus features.

```bash
make wipe
```
> Removes the MiniLibX (mlx) library files, forcing the compilation sequence to re-download them.

```bash
make leaks LEAK_ARGS="./path/to/scene.cub"
```
> Runs the **`cub3D`** binary through ***Valgrind*** to check for memory leaks. The *LEAK_ARGS* variable allows you to specify the target scene.

```bash
make parse_tests
```
> Runs the **`cub3D`** binary with various custom test scenes. Each test gives a breif description of the map being tested, and the execution will be interrupted if an unexpected output occurs.

```bash
make add_parse_test_permit
make rm_parse_test_permit
```
> Creates or removes, respectively, specific problematic scene files and invalid textures. Primarily designed for the *`parse_tests`* sequence, but can be run independently to manually examine the test cases.

```bash
make val_parse_tests
```
> Runs the **`cub3D`** binary with various custom test scenes while using ***Valgrind***. It is essentially equivalent to the *`parse_tests`* rule, with the added benefit of memory leak analysis.

```bash
make normloop
```
> Creates a *'normloop.sh'* shell script to run the 42 Norminette in a continuous loop, allowing you to see formatting errors disappear in real time as you fix them.
---

## 🧾 Final Notes 🐆🦝

If you made it this far…

Merry Christmas.
Take a break. Drink water. Maybe eat an alheira arepa.
Keep calm and eat alheira!!

The Verdant Veil is only safe because of you.

🍃💚✨

<p align="center">
 <img src="./Documentation/README_img/VerdantCoverArt.jpeg" alt="The Verdant CoverArt" width="1000">
</p>
