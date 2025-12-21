# Networking in Video Games: An Exploration of Networking Principles in Team Fortress 2

**Author:** Joey Kaplan  
**Date Created:** November 10, 2025  
**Last Modified:** December 15, 2025  
**Repository:** [Networking In Video Games](https://github.com/joeykap123/tf2-netcode-analysis) </br>
**Copyright:** © 2025 Joey Kaplan  

# About This Project
This project began during my junior year, while taking CS 4400: Computer Systems at the University of Utah. As we explored networking concepts towards the latter portion of the semester, I became fascinated with concepts such as client-server communication and synchronization. I decided to implement a project exploring various networking principles in one of my favorite games--Team Fortress 2.  
**TODO::** Make this sound nicer  
This project seeks to analyze various networking principles in Team Fortress 2, a game by Valve. Within this project, we will explore networking concepts and how they relate to online gaming. We will also explore phenomenons of cheating and how these methods are executed.
> **NOTE:**
> This project is under active development and will be expanded with additional simulations and analysis.
</br>

## Ethical & Legal Disclaimer

This project is intended strictly for educational and research purposes.
It does not interact with live game servers, clients, or real network traffic,
and must not be used to create cheats or exploits.

For full details, see [Disclaimer.md](Disclaimer.md).

## Table of Contents
- [About This Project](#about-this-project)
- [Installation](#installation)
- [Project Structure](#project-structure)
- [Data Folder](#data-folder)
- [Source Folder](#src-folder)
- [Docs Folder](#docs-folder)
- [License](#license)

# Installation
    TODO::::

# Project Structure
```
NetworkingInVideoGames/
├── src/
│   ├── Player.h                # Defines the Player class and its attributes
│   ├── Player.cpp              # Implements Player methods and logic for updating state
│   ├── Position.h              # Defines a 3D Position class for player coordinates
│   ├── Position.cpp            # Implements Position methods and helper functions
│   ├── Interpolation.h         # Declares interpolation algorithms used to smooth movement
│   ├── Interpolation.cpp       # Implements interpolation strategies (linear, cubic, etc.)
│   ├── NetworkCondition.h      # Defines network simulation parameters (latency, jitter, packet loss)
│   └── NetworkCondition.cpp    # Implements network simulation logic
│
├── data/
|   └── data.json               # Synthetic dataset of player positions and network events
|
├── docs/
│   ├── README.md               # Project README
│   ├── ResearchDoc.md          # Research notes and networking analysis
│   ├── CodeAnalysis.md         # Source SDK 2013 source code analysis
│   ├── References.md           # External references and sources
│   └── Disclaimer.md           # Legal and ethical disclaimer
└── LICENSE                     # MIT License
```
# src Folder
Contains all C++ source code for the simulation, including classes for players, positions, interpolation algorithms, and network condition simulations.

# data Folder
Contains synthetic datasets of player positions and network events used for testing and visualization.  

> **NOTE:**
>
> All datasets in this project are **made-up, synthetic examples** created for testing and visualization.  
> No real network traffic or gameplay data was collected.

# docs Folder
Contains project documentation, research notes, code analysis, references, and the legal/ethical disclaimer.

# Features & Key Components
Basically take resume section and tweak it to be more technical, instead of appealing to employers.


# License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
© 2025 Joey Kaplan. All rights reserved except as permitted under the MIT License.
