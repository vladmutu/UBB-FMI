# Let's define a function that arranges the benches in each room based on its dimensions and the number of benches.
import numpy as np


def arrange_benches(width, height, num_benches):
    """
    Arranges benches in a room of given width and height.
    Benches have a size of 1x3, and are placed horizontally.

    Parameters:
    - width: Width of the room (number of columns).
    - height: Height of the room (number of rows).
    - num_benches: Total number of benches to place in the room.

    Returns:
    - A 2D numpy array representing the room layout.
    """
    # Initialize the room layout with zeros
    room_layout = np.zeros((height, width), dtype=int)

    bench_id = 1  # Starting ID for the benches
    for row in range(height):
        for col in range(width - 2):  # Ensure we leave enough space for a 1x3 bench
            # Place a bench only if there are benches left
            if bench_id <= num_benches:
                # Check if we have a 3-column space available to place the bench horizontally
                if room_layout[row, col] == 0 and room_layout[row, col + 1] == 0 and room_layout[row, col + 2] == 0:
                    # Place the bench with its ID in 3 consecutive cells
                    room_layout[row, col:col + 3] = bench_id
                    bench_id += 1
            else:
                # If we placed all benches, return the layout
                return room_layout

    return room_layout

# Parsing the input file content
lines = open("in.txt", "r").readlines().strip().split("\n")
num_rooms = int(lines[0].strip())  # First line indicates the number of rooms
room_specs = [tuple(map(int, line.strip().split())) for line in lines[1:]]  # Specs for each room

# Generating room layouts for each room and storing results
room_layouts = []
for width, height, num_benches in room_specs:
    layout = arrange_benches(width, height, num_benches)
    room_layouts.append(layout)

# Displaying the layout of the first room as an example
room_layouts[0]
