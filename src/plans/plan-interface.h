// The Notices and Disclaimers for Ocean Worlds Autonomy Testbed for Exploration
// Research and Simulation can be found in README.md in the root directory of
// this repository.

#ifndef Ow_Plan_Interface_H
#define Ow_Plan_Interface_H

// PLEXIL interface: commands, lookups, library plans

// Lander commands

// The following commands perform only the path planning for the given activity.

Command dig_circular (Real x, Real y, Real depth, Real ground_pos,
                      Boolean radial); // true means parallel to lander arm

Command dig_linear (Real x, Real y, Real depth, Real length,
                    Real ground_pos);

// This dumps the scoop at the given location; can be used for removing tailings
// as well as delivering a sample to the receptacle.
Command deliver_sample (Real x, Real y, Real z);

Command grind (Real x, Real y, Real depth, Real length, Boolean radial, Real ground_pos);

Command guarded_move (Real x, Real y, Real z,
                      Real dir_x, Real dir_y, Real dir_z,
                      Real search_distance);

Command unstow();  // move from stowed position to a "ready" position

// move from "ready" position to stowed position; REQUIRES unstow() first
Command stow();


// This command sends the planned trajectory to Gazebo, i.e. moves real arm
Command publish_trajectory();

// Utility commands

Command log_info (...);
Command log_warning (...);
Command log_error (...);


// Lookups

Boolean Lookup Running (String operation_name);
Boolean Lookup Finished (String operation_name);
Boolean Lookup HardTorqueLimitReached (String joint_name);
Boolean Lookup SoftTorqueLimitReached (String joint_name);
Boolean Lookup GroundFound;
Real    Lookup GroundPosition;

// Lander operations

LibraryAction Stow ();
LibraryAction Unstow ();
LibraryAction GuardedMove (In Real X, In Real Y, In Real Z,
                           In Real DirX, In Real DirY, In Real DirZ,
                           In Real SearchDistance);
LibraryAction Grind (In Real X, In Real Y, In Real Depth, In Real Length,
                     In Boolean Radial, In Real GroundPos);
LibraryAction DigCircular (In Real X, In Real Y, In Real Depth,
                           In Real GroundPos, In Boolean Radial);
LibraryAction DeliverSample (In Real X, In Real Y, In Real Z);

// Does nothing
LibraryAction Stub (In String desc);

#endif