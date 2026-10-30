# Cub3D - Hell or Paradise

<p align="center">
  A 3D raycasting game developed in C using MiniLibX, featuring two completely different visual worlds: Hell and Paradise.
</p>

<p align="center">
  <strong>42 Network - 1337 Coding School</strong>
</p>

<p align="center">
  🏆 One of the Top 2 Cub3D Projects in Our Promotion
</p>

---

## 📖 About the Project

**Cub3D - Hell or Paradise** is a graphical project developed as part of the 42 Network curriculum. The goal is to create a 3D game environment using the raycasting technique, inspired by classic first-person games such as Wolfenstein 3D.

What makes our Cub3D project different is its creative concept and visual design.

Instead of creating a traditional maze environment, we designed two completely different worlds:

- 🔥 **Hell:** A dark and hellish environment with its own visual identity.
- 😇 **Paradise:** A bright and heavenly environment with a completely different atmosphere.

Players can switch between these two worlds using the keyboard, experiencing different environments within the same game.

The project combines graphics programming, game mechanics, texture rendering, and creative visual design.

## 🌍 Game Worlds

### 🔥 Hell

A dark environment designed around a hell-themed atmosphere, featuring custom textures and a devil character.

### 😇 Paradise

A heavenly environment with a different visual identity, featuring paradise-themed textures and an angel character.

### Switching Between Worlds

The game allows players to choose their preferred environment directly from the keyboard:

| Key | Action |
|---|---|
| `1` | Select Hell |
| `2` | Select Paradise |

## ✨ Features

### Mandatory Part

- Real-time 3D rendering using Raycasting.
- First-person perspective gameplay.
- Two selectable environments: Hell and Paradise.
- Custom visual design for both environments.
- Wall texture rendering.
- XPM texture loading using MiniLibX.
- Player movement and camera rotation.
- Map parsing and validation.

### Bonus Part

We implemented the full bonus part, extending the game with additional graphical and gameplay features.

- **Minimap:** Displays a top-down representation of the map, showing the player's current position.
- **Wall Collision:** Prevents the player from walking through walls.
- **Interactive Characters:** Press `N` to display a special character in the selected environment.
  - In Paradise, an angel appears and welcomes the player with: "Welcome to Paradise".
  - In Hell, a devil appears and welcomes the player with: "Welcome to Hell".
- **Animated Sprites:** Additional animated character visuals.
- **Interactive Doors:** Doors that can open and close.
- **Mouse Camera Rotation:** Rotate the player's point of view using the mouse.

## 🛠️ Technologies Used

| Technology | Description |
|---|---|
| C | Main programming language |
| MiniLibX (MLX) | Graphics library and window management |
| XPM | Texture and image rendering |
| Raycasting | Real-time 3D rendering technique |
| Makefile | Project compilation |
| Linux / UNIX | Development environment |

## 🎮 Controls

| Key | Action |
|---|---|
| `1` | Switch to Hell |
| `2` | Switch to Paradise |
| `W` | Move forward |
| `S` | Move backward |
| `A` | Move left |
| `D` | Move right |
| `←` / `→` | Rotate camera |
| `N` | Display the environment's character |
| `ESC` | Exit the game |

## 🚀 Installation & Usage

### 1. Clone the repository

```bash
git clone <repository-url>
cd cub3d
```

### 2. Compile the project

```bash
make
```

### 3. Run the game

```bash
./cub3D maps/map.cub
```

*Replace the executable and map names with the ones provided in the repository if they differ.*

### 4. Clean generated files

```bash
make clean
make fclean
make re
```

## 📸 Screenshots

### 🔥 Hell

<!-- Add Hell gameplay screenshot here -->

### 😇 Paradise

<!-- Add Paradise gameplay screenshot here -->

### 🗺️ Minimap & Bonus Features

<!-- Add minimap and character screenshots here -->

## 📚 What I Learned

Working on Cub3D helped me develop practical knowledge of:

- Raycasting algorithms and 3D rendering fundamentals.
- Graphics programming using MiniLibX.
- Loading and rendering XPM textures.
- Image manipulation and pixel rendering.
- Event handling and keyboard interactions.
- Player movement, camera rotation, and collision detection.
- Map parsing and validation.
- Sprite rendering and animation.
- Game development and real-time rendering.
- Collaborative development and Git workflow.
- Combining technical implementation with creative UI/UX and visual design.

## 👥 Contributors

Developed collaboratively by:

- **Aymane Kahir**
- **[@IFaleh](https://github.com/IFaleh)**

## 🏆 Project Recognition

This project was recognized as one of the **Top 2 Cub3D projects in our 1337 promotion**, reflecting our effort in combining technical implementation with creative visual design.

---

<p align="center">
  Designed and developed by Aymane Kahir & IFaleh.
</p>
