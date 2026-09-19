<p align="center"><i>This project has been created as part of the 42 curriculum by lde-san- & rdeimaos</i></p>

<h1 align="center">🍃🧿 Cub3D - The Verdant Veil 🧿🍃</h1>
<p align="center"><b><em>Sometimes courage and wisdom, can come in the smallest package.</em></b></p>

---

## 🎮 Description
Cub3D is an homage to the legendary Wolfenstein 3D. The project explores the mathematical foundations of early 3D gaming to create a first-person raycasting engine completely in C. At its core, the project focuses on map parsing, texture rendering, event handling, and building a simple game loop. The resulting program is capable of rendering walls with the selected textures, scaling them dynamically based on their distance from the player to create a realistic 3D perspective.


## ⚙️ Instructions

There are 3 executables that you can create with the provided makefile:

### 🛠️ Compilation

- **make** : Will compile the binary **"cub3D"** as intended by the project's mandatory section of the subject.

```bash
make
```

- **make bonus** : Will compile the previous binary **"cub3D"**, with some additional features from the project's bonus section of the subject.

```bash
make bonus
```

- **make showcase** : Will compile the previous binary **"cub3D"**, with the additional features from the bonus section, along with an executable shell script **"showcase.sh"**. That will immediately begin running, iterating through 4 maps designed to explore the capabilities of the project.

```bash
make showcase
```
### 🛠️ Running the Game

Following any of the compilation instructions above, will leave you with a **"cub3D"** binary, that you can run passing the path to a scene file as a parameter.

```bash
./cub3D ./maps/scene_n.cub
```

Furthermore, if you compiled with the **make showcase** command, you can simply run the **"showcase.sh"** shell script as it is.

```bash
./showcase.sh
```

Or run it passing a number **n** as a parameter, to start the script from a specific scene.

```bash
./showcase.sh n
```

>The scene file needs to fulfill a series of conditions specified in the project's subject. In summary, it is a text file with the .cub suffix, that will be interpreted by the program. Below is an example of the contents of the file:

```bash
NO ./path_to_the_north-facing_texture
SO ./path_to_the_south-facing_texture
WE ./path_to_the_west-facing_texture
EA ./path_to_the_east-facing_texture

F 0,0,0
C 225,225,225

11111
10N01
11111
```
>The program is designed to accept only this information. However, the pieces on information will be able to be interpreted in any other and even with spaces in the middle as long as:
>
> - The *map* (The region with ones and zeroes), is at the end of the file.
> - The *Identifiers* (NO, SO, WE, EA, F, C), are exacly as shown in the example. For example, for the identifier "NO", if the scene only contains "N", "N   O" or "no", the scene will be considered invalid.
> - The paths to the textures are not separated by spaces. (Unless the name of the textures or directories have them).
> - The colors are within the valid values (0 - 255). these colors should be defined with the typical RGB format, however, they can have any number or white spaces around or in between the values.
>
> **The information is interpreted as follows:**
>
> #### 🎬 Scene Identifiers
>
> - **NO** : This *Identifier* Marks the line where the path to the north texture is stored. Next to it at some point it should have the **./path_to_the_north-facing_texture**.
> - **SO** : This *Identifier* Marks the line where the path to the north texture is stored. Next to it at some point it should have the **./path_to_the_south-facing_texture**.
> - **WE** : This *Identifier* Marks the line where the path to the north texture is stored. Next to it at some point it should have the **./path_to_the_west-facing_texture**.
> - **EA** : This *Identifier* Marks the line where the path to the north texture is stored. Next to it at some point it should have the **./path_to_the_east-facing_texture**.
> - **F** : This *Identifier* Marks the line where the color for the floor is defined.
> - **C** : This *Identifier* Marks the line where the color for the ceiling is defined.
>
> #### 🗺️ Map Format
> The characters in the map are interpreted as follows:
>
> - **[1]**	Wall.
> - **[0]**	Empty space.
> - **[P]**	The Player's starting position. Facing North.
> - **[S]**	The Player's starting position. Facing South.
> - **[W]**	The Player's starting position. Facing West.
> - **[E]**	The Player's starting position. Facing East.
>
> The map can have any shape, and it can be separated by blank rows or columns, as long as all regions described are completely surrounded by walls.
> The map must include a starting position for the player. This position will be marked by a character *(N, S, W, or E)*, that will define "Where" the player will be looking at the start of the program.
> The program will analyze the region that the player can access. If there are remote areas or inaccesible rooms, defined in the map, they will not be part of the final render.

### 🎮 Controls
- **WASD**					→	*Move The Player.*
- **Arrow Key Left**		→	*Rotate point of view Left.*
- **Arrow Key Right**		→	*Rotate point of view Right.*
- **ESC**					→	*Exit game.*
- **Window Close Button**	→	*Exit game.*

---

## 🧠 Technical Overview

- Language: **C**

- Graphics API: **MiniLibX (mlx)**

	- **Dynamic 2D Camera:** Viewport offset system for rendering massive, scrolling levels.
	- **Direct Buffer Rendering:** Bypasses standard grid-drawing by pushing pixels directly to the image data buffer.
	- **Visual Lerping:** Separates logical grid coordinates from visual coordinates for fluid, sub-tile sprite gliding.
	- **Real-Time Sprite Flipping:** Inverts texture byte-reading mathematically to face moving directions without duplicated assets.
	- **Procedural Autotiling:** Evaluates neighboring matrix characters to dynamically assign corner and border textures.
	- **Padded AABB Collision:** Custom hitboxes with pixel tolerances for snug and fair interactions.
	- **Pseudo-Random AI:** Independent enemy movement logic and pathing.
	- **Event Handling:** Fluid window management and asynchronous keypress listening.
	- **Map Parsing & Validation:** Strict error-checking and flood-fill pathfinding.
	- **Resource Management:** Bulletproof allocation and cleanup *(because leaks, am I right?)*.

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
make dependencies
```
> Minilibx requires some dependencies that you might not have installed. If that's the case, this rule should fix your compilation issues. **Requires sudo access**.

```bash
make open
```
> Opens all the source files that were created for this project.

```bash
make clean
```
> Removes the object files, created during compilation.

```bash
make fclean
```
> Runs **make clean** and removes the **so_long** executable.

```bash
make re
```
> Runs **make fclean** and re-compiles the **so_long** executable.

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
