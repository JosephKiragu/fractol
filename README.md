# Fractol

![My Image](https://github.com/JosephKiragu/fractol/blob/master/images/fractal.jpeg)

Fractol is a C program that generates fractal images, specifically Julia, Mandelbrot, and Rabbit fractals. It uses the MiniLibX library to handle window management, user input, and image rendering. The project provides an interactive environment for users to explore different fractals and customize their appearance.

## Features

- Render Julia, Mandelbrot, and Rabbit fractals
- Zoom in and out with mouse scroll
- Pan the view using arrow keys
- Adjust the color scheme dynamically
- Control the iteration count and custom constants for Julia and Rabbit fractals

## Installation

1. Clone the repository:
```
git clone https://github.com/yourusername/fractol.git
```

2. Navigate to the project folder:
```
cd fractol
```

3. Compile the program using the provided Makefile:
```
make
```

4. Run the program with the desired fractal type as an argument:
```
./fractol julia
```
Or use `mandelbrot` or `rabbit` as the argument for other fractal types.

## Usage

To explore the fractals, use the following controls:

- Zoom: Scroll up/down with the mouse
- Pan: Use arrow keys
- Change color scheme: Press spacebar
- Exit the program: Press ESC or close the window

To customize the fractal properties, use command-line arguments:

```
./fractol [fractal_type] [iteration_count] [c_real] [c_imaginary]
```

For example, to render a Julia fractal with 100 iterations and custom constants:

```
./fractol julia 100 -0.8 0.156
```

## Dependencies

- MiniLibX: A minimalistic library for handling window management and user input on macOS and Linux. It's included as a submodule in the repository.
