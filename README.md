# Panoramix - Multi-threaded Village Simulation

A C program that simulates the interactions between a druid (Panoramix) and villagers in a Gaulish village using multi-threading. The program demonstrates thread synchronization and resource management in a concurrent environment.

## Project Overview

This project simulates the famous Gaulish village where:
- Panoramix (the druid) prepares magic potions
- Villagers need to drink the potion to fight Romans
- Resources and actions are synchronized using threads and mutexes

## Project Structure

```
Panoramix/
├── src/
│   ├── main.c          # Program entry point
│   ├── panoramix.c     # Druid logic implementation
│   ├── run_druid.c     # Druid thread management
│   ├── run_villager.c  # Villager thread management
│   └── init_struct.c   # Data structure initialization
├── include/            # Header files
└── Makefile           # Build configuration
```

## Building the Project

To compile the project:

```bash
make
```

This will generate the `panoramix` executable.

## Usage

```bash
./panoramix nb_villagers pot_size nb_fights nb_refills
```

### Parameters

- `nb_villagers`: Number of villagers in the village
- `pot_size`: Number of portions per pot
- `nb_fights`: Number of fights each villager should participate in
- `nb_refills`: Number of times the druid can refill the pot

### Example

```bash
./panoramix 5 10 5 3
```
This will simulate:
- 5 villagers
- A pot that can hold 10 portions
- Each villager will fight 5 times
- The druid can refill the pot 3 times

## Implementation Details

The program uses POSIX threads to manage concurrent actions:
- One thread for the druid
- One thread per villager
- Synchronized access to the magic potion pot
- Thread-safe communication between druid and villagers

## Error Handling

The program includes error handling for:
- Invalid command-line arguments
- Thread creation failures
- Resource allocation issues

## Cleaning Up

To clean the project:
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Clean and rebuild the project

## Testing

Run the unit tests with:

```bash
make tests_run
```

## License

This project is licensed under the terms provided in the LICENSE file.

## Contributing

Feel free to submit issues and enhancement requests. 