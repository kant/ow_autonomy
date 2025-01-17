The Notices and Disclaimers for Ocean Worlds Autonomy Testbed for Exploration
Research and Simulation can be found in README.md in the root directory of
this repository.

PLEXIL plans
============

This directory contains PLEXIL plans that implement onboard autonomy for Ocean
World landers, as supported by the OceanWATERS software testbed.

Plans are executed by starting the autonomy node, which takes as an argument the
name of the compiled plan, which is the same name as the `.plp` files here,
except with extension `.plx`.  The default plan, when not supplied, is Demo.plx,
which is he compilation of Demo.plp.  Compiled files are found only in the
`devel/etc/plexil` directory of your workspace.

Not all of these plans may be executed directly by the autonomy node, because of
some of them are library plans.  Only _top level_ plans may be run directly.  A
top level plan is one having no parameters, i.e. no `In` or `InOut` variable
declarations near the top.

Descriptions of some key plans, and other files of interest, are as follows.
See the comments inside all the plans for more information.

1. ReferenceMission1 : models a portion of Sol 0 of the Europa Lander reference
   mission defined by JPL.

2. EuropaMission: a variant of the above that includes _checkpointing_, a new
   PLEXIL feature that supports robust plan resumption after a reboot.
   Checkpoint filers are saved to ~/.ros by default; the location can be
   customized in `ow-config.xml`.  You should be able to kill the autonomy node
   at arbitrary points during this plan's execution, restart the node, and see
   the correct behavior.

3. Demo: Default plan for the autonomy node.  Exercises a few short sequences of
   arm and antenna operations.

4. TestAntennaCamera: A short panoramic imaging demo.

5. TorqueTest: Overtorque detection.  This plan attempts to push the scoop into
   the ground, which creates joint over-torquing warnings and errors.

6. TestPlanning: Concurrency demo.  This runs the arm planning ROS service,
   while concurrently printing an "in progress" message.  Note that ROS services
   are typically blocking, but the PLEXIL interface threads them to allow
   concurrency.

7. TestActions: ROS Action demo.  This plan runs a dummy GuardedMove action (not
   connected to simulator) concurrently with the real GuardedMove service.

