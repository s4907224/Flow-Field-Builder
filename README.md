# Flow Field Generator

This program generates a set of flow fields from a given map image.
A python script translates the image into a readable format for the main C++ program, which then divides the 256*256 map into 1024 8 * 8 sections.

***TODO***
- ~~Generate linker map to link the sections together~~ *Done*
- ~~Use linker map to find waypoints and crossings between sections to link any given tile on the map.~~ *Done*
- Use these waypoints to construct a route to be used by a peep in BEAN
- Possibly better memory usage
- Implement into BEAN's main code.