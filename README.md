# Solar System Simulation

An interactive 3D simulation of the Solar System built with OpenGL, showcasing the planets orbiting around the sun with realistic textures and lighting effects.

## Features

- Realistic 3D rendering of all planets in the Solar System
- Textured surfaces for all celestial bodies (Sun, planets, and moon)
- Accurate orbital paths and rotations
- Dynamic lighting effects simulating sunlight
- Interactive starfield background
- Smooth animations and transitions
- Camera controls for viewing the simulation from different angles

## Dependencies

The project requires the following libraries:
- OpenGL
- GLFW3
- GLAD
- SDL2
- SDL2_image

## Required Texture Files

The following texture files should be present in the project directory:
- sun_texture.jpg
- earth_texture.jpg
- mercury_texture.jpg
- venus_texture.jpg
- mars_texture.jpg
- jupiter_texture.jpg
- saturn_texture.jpg
- uranus_texture.jpg
- neptune_texture.jpg
- moon_texture.jpg

## Building and Running

1. Make sure you have all the required dependencies installed
2. Clone this repository
3. Compile the project:
   ```bash
   g++ final.cpp -o solar_system -lGL -lGLU -lglfw -lSDL2 -lSDL2_image
   ```
4. Run the simulation:
   ```bash
   ./solar_system
   ```

## Features in Detail

### Planet System
- Accurate scaling of planets relative to each other
- Realistic orbital paths
- Individual rotation speeds for each planet
- Textured surfaces using high-quality planet textures

### Lighting System
- Ambient lighting for basic visibility
- Diffuse lighting for realistic surface illumination
- Specular highlights for reflective effects
- Dynamic light source centered at the sun

### Background
- Dynamic starfield with randomly generated stars
- Gradient background simulating space
- Orbital paths visualization

## Controls

The simulation provides various viewing controls (refer to the source code for specific key bindings).

## Technical Details

The project uses modern OpenGL features including:
- Texture mapping for realistic planet surfaces
- Quadric objects for smooth sphere generation
- Matrix transformations for orbital movements
- Lighting calculations for realistic illumination
- Viewport management for proper display

## Contributing

Feel free to contribute to this project by:
- Adding new features
- Improving the physics simulation
- Enhancing the visual effects
- Fixing bugs
- Optimizing performance

## License

This project is open source and available under the MIT License.
