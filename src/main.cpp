#include <cstdlib>
#include <climits>
#include <iostream>
#include <array>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#include <unistd.h>
#include <glm/vec2.hpp>
#include <glm/gtx/string_cast.hpp>
#include "../include/map.h"

bool gridDone = false;
bool gridRunning = false;
bool linkerDone = false;
bool linkerRunning = false;
int mapsDone = 0;
int totalMaps = 0;
int junctionsDone = 0;
int totalJunctions = 0;
bool etaDirty = false;
enum directionEnum {d0 = 9, dN = 1, dNE = 2, dE = 3, dSE = 4, dS = 5, dSW = 6, dW = 7, dNW = 8, dNone = 0, dNoRoute = 10};

void spinDijkstra()
{
  while (!gridRunning)
  {
    nanosleep((const struct timespec[]){{0, 25000L}}, NULL);
  }
  auto t1 = std::chrono::high_resolution_clock::now();
  auto t2 = std::chrono::high_resolution_clock::now();
  float delta;
  int percent = 0;
  std::__cxx11::string tString;
  while(!gridDone)
  {
    t2 = std::chrono::high_resolution_clock::now();
    delta = float(std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count());
    if (etaDirty)
    {
      percent = int((float(mapsDone) / float(totalMaps)) * 100.f);
      float tpm = delta/float(mapsDone);
      float trem = (float(totalMaps) - float(mapsDone)) * tpm;
      while(true)
      {
        tString = std::to_string(int(trem)) + 's';
        if (trem > 86400)
        {
          int days = int(trem / 86400.f);
          int hours = int(trem / 3600.f) - (days * 24);
          int minutes = int(trem / 60.f) - (hours * 60) - (days * 1440);
          int seconds = int(trem - (minutes * 60) - (hours * 3600) - (days * 86400));
          tString = std::to_string(days) + "d :" + std::to_string(hours) + "h :" + std::to_string(minutes) + "m :" + std::to_string(seconds) + 's';
          break;          
        }
        if (trem > 3600)
        {
          int hours = int(trem / 3600.f);
          int minutes = int(trem / 60.f) - (hours * 60);
          int seconds = int(trem - (minutes * 60) - (hours * 3600));
          tString = std::to_string(hours) + "h :" + std::to_string(minutes) + "m :" + std::to_string(seconds) + 's';
          break;
        }
        if (trem > 60)
        {
          int minutes = int(trem / 60.f);
          int seconds = int(trem - (minutes * 60));
          tString = std::to_string(minutes) + "m :" + std::to_string(seconds) + 's';
          break;
        }
        break;
      }
      etaDirty = false;
    }

    std::cout << "\rDijkstra ⠁ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")   "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (gridDone) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rDijkstra ⠂ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")   "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (gridDone) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rDijkstra ⠄ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")   "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (gridDone) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rDijkstra ⡀ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")   "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (gridDone) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rDijkstra ⢀ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")   "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (gridDone) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rDijkstra ⠠ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")   "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (gridDone) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rDijkstra ⠐ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")   "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (gridDone) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rDijkstra ⠈ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")   "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (gridDone) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
  }
}

void spinLinker()
{
  while (!linkerRunning)
  {
    nanosleep((const struct timespec[]){{0, 25000L}}, NULL);
  }
  auto t1 = std::chrono::high_resolution_clock::now();
  auto t2 = std::chrono::high_resolution_clock::now();
  float delta;
  int percent = 0;
  std::__cxx11::string tString;
  while(!linkerDone)
  {
    t2 = std::chrono::high_resolution_clock::now();
    delta = float(std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count());
    if (etaDirty)
    {
      percent = int((float(junctionsDone) / float(totalJunctions)) * 100.f);
      float tpm = delta/float(junctionsDone);
      float trem = (float(totalJunctions) - float(junctionsDone)) * tpm;
      while(true)
      {
        tString = std::to_string(int(trem)) + 's';
        if (trem > 86400)
        {
          int days = int(trem / 86400.f);
          int hours = int(trem / 3600.f) - (days * 24);
          int minutes = int(trem / 60.f) - (hours * 60) - (days * 1440);
          int seconds = int(trem - (minutes * 60) - (hours * 3600) - (days * 86400));
          tString = std::to_string(days) + "d :" + std::to_string(hours) + "h :" + std::to_string(minutes) + "m :" + std::to_string(seconds) + 's';
          break;          
        }
        if (trem > 3600)
        {
          int hours = int(trem / 3600.f);
          int minutes = int(trem / 60.f) - (hours * 60);
          int seconds = int(trem - (minutes * 60) - (hours * 3600));
          tString = std::to_string(hours) + "h :" + std::to_string(minutes) + "m :" + std::to_string(seconds) + 's';
          break;
        }
        if (trem > 60)
        {
          int minutes = int(trem / 60.f);
          int seconds = int(trem - (minutes * 60));
          tString = std::to_string(minutes) + "m :" + std::to_string(seconds) + 's';
          break;
        }
        break;
      }
      etaDirty = false;
    }

    std::cout << "\rLinker ⠁ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")     "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (linkerDone) {std::cout<<"\nLinker complete.\nCrunching links...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rLinker ⠂ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")     "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (linkerDone) {std::cout<<"\nLinker complete.\nCrunching links...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rLinker ⠄ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")     "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (linkerDone) {std::cout<<"\nLinker complete.\nCrunching links...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rLinker ⡀ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")     "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (linkerDone) {std::cout<<"\nLinker complete.\nCrunching links...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rLinker ⢀ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")     "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (linkerDone) {std::cout<<"\nLinker complete.\nCrunching links...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rLinker ⠠ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")     "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (linkerDone) {std::cout<<"\nLinker complete.\nCrunching links...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rLinker ⠐ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")     "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (linkerDone) {std::cout<<"\nLinker complete.\nCrunching links...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rLinker ⠈ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% complete"<<std::setprecision(6)<<", time remaining: "<<tString<<")     "<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (linkerDone) {std::cout<<"\nLinker complete.\nCrunching links...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
  }
}

struct node
{
  bool unvisited = true;
  bool enabled = true;
  glm::ivec2 loc;
  int locX() const;
  int locY() const;
  float dist = FLT_MAX;
  std::vector<node*> nbrs;
  std::vector<node*> flowNbrs;
};

int node::locX() const
{
  return int(loc.x);
}

int node::locY() const
{
  return int(loc.y);
}

struct junction
{
  glm::ivec2 nodeLocA;
  int sectionA;
  glm::ivec2 nodeLocB;
  int sectionB;
  float dist = FLT_MAX;
  std::vector<int> nbrs;
  std::vector<int> nbrsSection;
  int pJunc = INT_MAX;
  bool unvisited = true;
  int junctionID;
  junction();
};

int junctionCounter = 0;

junction::junction()
{
  junctionID = junctionCounter;
  junctionCounter++;
}

struct pathStorage
{
  typedef std::array<int, 64> singleFlow;
  typedef std::array<singleFlow, 64> sectionFlow;
  typedef std::vector<sectionFlow> allFlow;
  typedef std::array<std::array<std::vector<node>, 64>, 1024> setNodes;
  typedef std::array<junction, 1984> junctionMap;
  typedef std::vector<junctionMap> linkerMap;
  typedef std::vector<junction*> linkerChain;
  singleFlow currentFlow;
  sectionFlow currentSectionFlow;
  allFlow allFlows;
  setNodes nodeSet;
  linkerMap linker;
  std::array<std::array<linkerChain, 1984>, 1984> linkerChains;
  std::array<std::array<std::vector<int>, 1984>, 1984> linkerSectionChain;
  //std::array<std::array<int, 1984>, 1984> linkerDistances; 
  std::array<junction, 1984> referenceJunctions; //NEEDED
};

pathStorage paths;

struct path
{
  std::vector<std::array<int, 2>> junction;
  std::vector<int> sections;
  glm::ivec2 destination;
};

struct mapInfo
{
  std::array<std::vector<int>, 1024> sectionMap;
};

mapInfo map;

float vectorLength(glm::vec2 a)
{
  float dist = sqrt(pow(a.x, 2) + pow(a.y, 2));
  return dist;
}

std::vector<node> dijkstraGrid(int sectionNo, int sourceX, int sourceY)
{
  gridRunning = true;
  int sectionOffset = sectionNo * 64;
  std::vector<node> vecNodes;
  int numUnvisitedNodes = 8 * 8;

  int y = 0;
  int x = 0;
  for (int i = sectionNo * 64; i < sectionNo * 64 + 64; i++)
  {
    x = i % 8;
    if (i != 0 && x == 0) {y++;}
    node n;
    n.loc.x = x;
    n.loc.y = y;
    if(mapGrid[i] != 1) {n.unvisited = true;}
    else                         {n.unvisited = false; n.enabled = false; numUnvisitedNodes--;}
    vecNodes.push_back(n);
  }

  for (size_t i = 0; i < vecNodes.size(); i++)
  {
    static int y = 0;
    if (i == 0) {y = 0;}
    int x = i % 8;
    if (x == 0 && i != 0) {y++;}
    
    if (x != 0 && vecNodes[i - 1].unvisited)
    {
      vecNodes[i].nbrs.push_back(&vecNodes[i - 1]);
      vecNodes[i].flowNbrs.push_back(&vecNodes[i - 1]);
      if (y != 0 && vecNodes[(y - 1) * 8 + (x - 1)].unvisited) {vecNodes[i].flowNbrs.push_back(&vecNodes[(y - 1) * 8 + (x - 1)]);}
      if (y != 8 - 1 && vecNodes[(y + 1) * 8 + (x - 1)].unvisited) {vecNodes[i].flowNbrs.push_back(&vecNodes[(y + 1) * 8 + (x - 1)]);}
    }
    if (x != 8 - 1)
    {
      if (vecNodes[i + 1].unvisited) {vecNodes[i].nbrs.push_back(&vecNodes[i + 1]);}
      if (vecNodes[i + 1].unvisited) {vecNodes[i].flowNbrs.push_back(&vecNodes[i + 1]);}
      if (y != 0 && vecNodes[(y - 1) * 8 + (x + 1)].unvisited) {vecNodes[i].flowNbrs.push_back(&vecNodes[(y - 1) * 8 + (x + 1)]);}
      if (y != 8 - 1 && vecNodes[(y + 1) * 8 + (x + 1)].unvisited) {vecNodes[i].flowNbrs.push_back(&vecNodes[(y + 1) * 8 + (x + 1)]);}
    }
    if (y != 0 && vecNodes[(y - 1) * 8 + x].unvisited)
    {
      vecNodes[i].nbrs.push_back(&vecNodes[(y - 1) * 8 + x]);
      vecNodes[i].flowNbrs.push_back(&vecNodes[(y - 1) * 8 + x]);
    }
    if (y != 8 - 1 && vecNodes[(y + 1) * 8 + x].unvisited)
    {
      vecNodes[i].nbrs.push_back(&vecNodes[(y + 1) * 8 + x]);
      vecNodes[i].flowNbrs.push_back(&vecNodes[(y + 1) * 8 + x]);
    }
    if (x == sourceX && y == sourceY)
    {
      for (size_t j = 0; j < vecNodes[i].nbrs.size(); j++)
      {
        vecNodes[i].nbrs[j]->dist = 1;
        vecNodes[i].dist = 0;
      }
    }
  }

  int startIndex = (sourceY * 8) + sourceX;
  int startNumRemNodes = numUnvisitedNodes;
  while (numUnvisitedNodes != 0)
  {
    int index = INT_MAX;
    for (size_t i = 0; i < vecNodes.size(); i++)
    {
      if (!vecNodes[i].unvisited) {continue;}
      if (index == INT_MAX)
      {
        index = i;
        continue;
      }
      if (vecNodes[i].dist < vecNodes[index].dist)
      {
        index = i;
      }
    }
    vecNodes[index].unvisited = false;

    for (size_t i = 0; i < vecNodes[index].nbrs.size(); i++)
    {
      float alt = vecNodes[index].dist + vectorLength(vecNodes[index].loc - vecNodes[index].nbrs[i]->loc);
      if (alt < vecNodes[index].nbrs[i]->dist)
      {
        vecNodes[index].nbrs[i]->dist = alt;
      }
    }
    numUnvisitedNodes--;
  }
  return vecNodes;
}

std::array<std::vector<node>, 64> calculateMap(int sectionNo)
{
  std::array<std::vector<node>, 64> allNodes;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      allNodes[j * 8 + i] = dijkstraGrid(sectionNo, i, j);
      mapsDone++;
      etaDirty = true;
    }
  }
  return allNodes;
}

pathStorage::singleFlow generateFlow(std::vector<node> nodes, int goalX, int goalY)
{
  pathStorage::singleFlow flow;
  int x = 0;
  int y = 0;
  for (int i = 0; i < 64; i++)
  {
    int dX;
    int dY;
    x = i % 8;
    if (i != 0 && x == 0) {y++;}
    if (nodes[i].enabled == false || nodes[i].flowNbrs.size() == 0)
    {
      flow[i] = dNone;
    }
    else if (nodes[i].dist == FLT_MAX)
    {
      flow[i] = dNoRoute;
    }
    else
    {
      if (x == goalX && y == goalY)
      {
        dX = 0;
        dY = 0;
      }
      else
      {
        float minDist = FLT_MAX;
        int index = INT_MAX;
        for (size_t j = 0; j < nodes[i].flowNbrs.size(); j++)
        {
          glm::vec2 dVector = nodes[i].flowNbrs[j]->loc - nodes[i].loc;
          float dist = nodes[i].flowNbrs[j]->dist;
          minDist = std::min(dist, minDist);
          if (minDist == dist) {index = j;}
        }
        dX = nodes[i].flowNbrs[index]->locX() - nodes[i].locX();
        dY = nodes[i].flowNbrs[index]->locY() - nodes[i].locY();
      }

      switch (dX)
      {
        case 0:
        {
          switch (dY)
          {
            case 0:
            {
              flow[i] = d0;
              break;
            }
            case -1:
            {
              flow[i] = dN;
              break;
            }
            case 1:
            {
              flow[i] = dS;
              break;
            }
          }
          break;
        }
        case 1:
        {
          switch (dY)
          {
            case 0:
            {
              flow[i] = dE;
              break;
            }
            case -1:
            {
              flow[i] = dNE;
              break;
            }
            case 1:
            {
              flow[i] = dSE;
              break;
            }
          }
          break;
        }
        case -1:
        {
          switch (dY)
          {
            case 0:
            {
              flow[i] = dW;
              break;
            }
            case -1:
            {
              flow[i] = dNW;
              break;
            }
            case 1:
            {
              flow[i] = dSW;
              break;
            }
          }
          break;
        }
      }
    }
  }
  return flow;
}

void printFlows()
{
  for (int section = 0; section < 1024; section++)
  {
    for (int flowInSection = 0; flowInSection < 64; flowInSection++)
    {
      int x = 0;
      int y = 0;
      std::cout<<"Section = "<<section + 1<<", flowNo: "<<flowInSection + 1<<'\n';
      for (int tileInFlow = 0; tileInFlow < 64; tileInFlow++)
      {
        x = tileInFlow % 8;
        if (tileInFlow != 0 && x == 0) {y++; std::cout<<"\n";}
        std::string arrow;
        switch (paths.allFlows[section][flowInSection][y * 8 + x])
        {
          case dN:
          {
            arrow = "🡑";
            break;
          }
          case dS:
          {
            arrow = "🡓";
            break;
          }
          case dE:
          {
            arrow = "🡒";
            break;
          }
          case dW:
          {
            arrow = "🡐";
            break;
          }
          case dNE:
          {
            arrow = "🡕";
            break;
          }
          case dNW:
          {
            arrow = "🡔";
            break;
          }
          case dSE:
          {
            arrow = "🡖";
            break;
          }
          case dSW:
          {
            arrow = "🡗";
            break;
          }
          case d0:
          {
            arrow = "\033[1;32mX\033[0m";
            break;
          }
          case dNone:
          {
            arrow = "\033[1;31m#\033[0m";
            break;
          }
          case dNoRoute:
          {
            arrow = "\033[1;33m0\033[0m";
            break;
          }
        }
        std::cout<<arrow<<' ';
      }
      std::cout<<"\n";
    }
  }
}

void getLinkerChain(int startJunction, int endJunction)
{
  pathStorage::linkerChain chain;
  std::vector<int> sections;
  chain.push_back(&paths.linker[startJunction][endJunction]);
  //paths.linkerDistances[startJunction][endJunction] = paths.linker[startJunction][endJunction].dist;
  bool doneChain = false;
  int pJIndex = paths.linker[startJunction][endJunction].pJunc;
  while (!doneChain)
  {
    if (pJIndex == INT_MAX) {doneChain = true; break;}
    chain.push_back(&paths.linker[startJunction][pJIndex]);
    pJIndex = paths.linker[startJunction][pJIndex].pJunc;
  }
  chain.push_back(&paths.linker[startJunction][startJunction]);
  for (size_t i = 0; i < chain.size() - 1; i++)
  {
    int commonSection = INT_MAX;
    if (chain[i]->sectionA == chain[i + 1]->sectionA) {sections.push_back(chain[i]->sectionA); continue;}
    if (chain[i]->sectionA == chain[i + 1]->sectionB) {sections.push_back(chain[i]->sectionA); continue;}
    if (chain[i]->sectionB == chain[i + 1]->sectionA) {sections.push_back(chain[i]->sectionB); continue;}
    if (chain[i]->sectionB == chain[i + 1]->sectionB) {sections.push_back(chain[i]->sectionB); continue;}
  }
  paths.linkerSectionChain[startJunction][endJunction] = sections;
  paths.linkerChains[startJunction][endJunction] = chain;
}

pathStorage::junctionMap dijkstraLinker(int sourceJunction)
{
  std::array<junction, 1984> junctions = paths.referenceJunctions;
  int numUnvisitedJunctions = 1984;

  for (size_t i = 0; i < junctions[sourceJunction].nbrs.size(); i++)
  {
    int commonSection = INT_MAX;
    int activeIndexSource = INT_MAX;
    int activeIndexNeighbour = INT_MAX;
    junctions[sourceJunction].dist = 0.f;
    if (junctions[sourceJunction].sectionA == junctions[junctions[sourceJunction].nbrs[i]].sectionA)
    {
      commonSection = junctions[sourceJunction].sectionA;
      activeIndexSource = (junctions[sourceJunction].nodeLocA.x % 8) + (8 * (junctions[sourceJunction].nodeLocA.y % 8));
      activeIndexNeighbour = (junctions[junctions[sourceJunction].nbrs[i]].nodeLocA.x % 8) + (8 * (junctions[junctions[sourceJunction].nbrs[i]].nodeLocA.y % 8));
    }
    if (junctions[sourceJunction].sectionA == junctions[junctions[sourceJunction].nbrs[i]].sectionB)
    {
      commonSection = junctions[sourceJunction].sectionA;
      activeIndexSource = (junctions[sourceJunction].nodeLocA.x % 8) + (8 * (junctions[sourceJunction].nodeLocA.y % 8));
      activeIndexNeighbour = (junctions[junctions[sourceJunction].nbrs[i]].nodeLocB.x % 8) + (8 * (junctions[junctions[sourceJunction].nbrs[i]].nodeLocB.y % 8));
    }
    if (junctions[sourceJunction].sectionB == junctions[junctions[sourceJunction].nbrs[i]].sectionA)
    {
      commonSection = junctions[sourceJunction].sectionB;
      activeIndexSource = (junctions[sourceJunction].nodeLocB.x % 8) + (8 * (junctions[sourceJunction].nodeLocB.y % 8));
      activeIndexNeighbour = (junctions[junctions[sourceJunction].nbrs[i]].nodeLocA.x % 8) + (8 * (junctions[junctions[sourceJunction].nbrs[i]].nodeLocA.y % 8));
    }
    if (junctions[sourceJunction].sectionB == junctions[junctions[sourceJunction].nbrs[i]].sectionB)
    {
      commonSection = junctions[sourceJunction].sectionB;
      activeIndexSource = (junctions[sourceJunction].nodeLocB.x % 8) + (8 * (junctions[sourceJunction].nodeLocB.y % 8));
      activeIndexNeighbour = (junctions[junctions[sourceJunction].nbrs[i]].nodeLocB.x % 8) + (8 * (junctions[junctions[sourceJunction].nbrs[i]].nodeLocB.y % 8));
    }
    junctions[junctions[sourceJunction].nbrs[i]].dist = paths.nodeSet[commonSection][activeIndexSource][activeIndexNeighbour].dist;
  }

  while (numUnvisitedJunctions != 0)
  {
    int index = INT_MAX;
    float minDist = FLT_MAX;
    for (size_t i = 0; i < junctions.size(); i++)
    {
      minDist = std::min(junctions[i].dist, minDist);
      if (!junctions[i].unvisited) {continue;}
      if (index == INT_MAX)
      {
        index = i;
        continue;
      }
      if (junctions[i].dist < junctions[index].dist)
      {
        index = i;
      }
    }
    junctions[index].unvisited = false;

    for (size_t i = 0; i < junctions[index].nbrs.size(); i++)
    {
      int commonSection = INT_MAX;
      int activeIndexSource = INT_MAX;
      int activeIndexNeighbour = INT_MAX;
      if (junctions[index].sectionA == junctions[junctions[index].nbrs[i]].sectionA)
      {
        commonSection = junctions[index].sectionA;
        activeIndexSource = (junctions[index].nodeLocA.x % 8) + (8 * (junctions[index].nodeLocA.y % 8));
        activeIndexNeighbour = (junctions[junctions[index].nbrs[i]].nodeLocA.x % 8) + (8 * (junctions[junctions[index].nbrs[i]].nodeLocA.y % 8));
      }
      if (junctions[index].sectionA == junctions[junctions[index].nbrs[i]].sectionB)
      {
        commonSection = junctions[index].sectionA;
        activeIndexSource = (junctions[index].nodeLocA.x % 8) + (8 * (junctions[index].nodeLocA.y % 8));
        activeIndexNeighbour = (junctions[junctions[index].nbrs[i]].nodeLocB.x % 8) + (8 * (junctions[junctions[index].nbrs[i]].nodeLocB.y % 8));
      }
      if (junctions[index].sectionB == junctions[junctions[index].nbrs[i]].sectionA)
      {
        commonSection = junctions[index].sectionB;
        activeIndexSource = (junctions[index].nodeLocB.x % 8) + (8 * (junctions[index].nodeLocB.y % 8));
        activeIndexNeighbour = (junctions[junctions[index].nbrs[i]].nodeLocA.x % 8) + (8 * (junctions[junctions[index].nbrs[i]].nodeLocA.y % 8));
      }
      if (junctions[index].sectionB == junctions[junctions[index].nbrs[i]].sectionB)
      {
        commonSection = junctions[index].sectionB;
        activeIndexSource = (junctions[index].nodeLocB.x % 8) + (8 * (junctions[index].nodeLocB.y % 8));
        activeIndexNeighbour = (junctions[junctions[index].nbrs[i]].nodeLocB.x % 8) + (8 * (junctions[junctions[index].nbrs[i]].nodeLocB.y % 8));
      }
      float alt = junctions[index].dist + paths.nodeSet[commonSection][activeIndexSource][activeIndexNeighbour].dist;
      if (alt < junctions[junctions[index].nbrs[i]].dist)
      {
        junctions[junctions[index].nbrs[i]].dist = alt;
        junctions[junctions[index].nbrs[i]].pJunc = index;
      }
    }
    numUnvisitedJunctions--;
  }
  junctionsDone++;
  etaDirty = true;
  return junctions;
}

void generateLinkerMap()
{
  linkerRunning = true;
  int junctionCounter = 0;
  for (int j = 0; j < 32; j++)
  {
    for (int i = 0; i < 32; i++)
    {
      if (i != 31)
      {
        glm::ivec2 currentSectionCoordsRight {i * 8 + 7, j * 8 + 3};
        junction junc;
        junc.sectionA = i + j * 32;
        junc.sectionB = junc.sectionA + 1;
        junc.nodeLocA = currentSectionCoordsRight;
        junc.nodeLocB = currentSectionCoordsRight;
        junc.nodeLocB.x += 1;
        paths.referenceJunctions[junctionCounter] = junc;
        map.sectionMap[junc.sectionA].push_back(junctionCounter);
        map.sectionMap[junc.sectionB].push_back(junctionCounter);
        junctionCounter++;
      }
      if (j != 31)
      {
        glm::ivec2 currentSectionCoordsTop {i * 8 + 3, j * 8 + 7};
        junction junc;
        junc.sectionA = i + j * 32;
        junc.sectionB = junc.sectionA + 32;
        junc.nodeLocA = currentSectionCoordsTop;
        junc.nodeLocB = currentSectionCoordsTop;
        junc.nodeLocB.y += 1;
        paths.referenceJunctions[junctionCounter] = junc;
        map.sectionMap[junc.sectionA].push_back(junctionCounter);
        map.sectionMap[junc.sectionB].push_back(junctionCounter);
        junctionCounter++;
      }
    }
  }
  for (int i = 0; i < 1984; i++)
  {
    for (int j = 0; j < 1984; j++)
    {
      if (i == j) {continue;}
      if (paths.referenceJunctions[i].sectionA == paths.referenceJunctions[j].sectionA ||
          paths.referenceJunctions[i].sectionA == paths.referenceJunctions[j].sectionB ||
          paths.referenceJunctions[i].sectionB == paths.referenceJunctions[j].sectionA ||
          paths.referenceJunctions[i].sectionB == paths.referenceJunctions[j].sectionB)
          {
            bool shouldAdd = true;
            for (size_t k = 0; k < paths.referenceJunctions[i].nbrs.size(); k++)
            {
              if (paths.referenceJunctions[paths.referenceJunctions[i].nbrs[k]].junctionID == paths.referenceJunctions[j].junctionID) {shouldAdd = false;}
            }
            paths.referenceJunctions[i].nbrs.push_back(j);
          }
    }
  }
  for (size_t i = 0; i < 1984; i++) {paths.linker.push_back(dijkstraLinker(i));}
  linkerDone = true;
  for (size_t i = 0; i < 1984; i++)
  {
    for (size_t j = 0; j < 1984; j++)
    {
      if (i == j) {continue;}
      getLinkerChain(i, j);
    }
  }
}

void run(bool printFlag)
{
  totalMaps = 8 * 8 * 1024;
  for (int i = 0; i < 1024; i++) {paths.nodeSet[i] = calculateMap(i);}
  gridDone = true;
  for (int section = 0; section < 1024; section++)
  {
    int x = 0;
    int y = 0;
    for (int flowInSection = 0; flowInSection < 64; flowInSection++)
    {
      x = flowInSection % 8;
      if (flowInSection != 0 && x == 0) {y++;}
      if (paths.nodeSet[section][flowInSection][flowInSection].enabled) {paths.currentFlow = generateFlow(paths.nodeSet[section][flowInSection], x, y);}
      else {paths.currentFlow = pathStorage::singleFlow();}
      paths.currentSectionFlow[flowInSection] = paths.currentFlow;
    }
    paths.allFlows.push_back(paths.currentSectionFlow);
  }
  if(printFlag) {printFlows();}
  totalJunctions = 1984;
  etaDirty = true;
  generateLinkerMap();
}

int convertVec2ToIndex(glm::ivec2 vec)
{
  return (vec.x % 8) + (8 * (vec.y % 8));
}

void getPath(glm::ivec2 sourceGlobal, glm::ivec2 destinGlobal)
{
  glm::ivec2 sourceLocal {sourceGlobal.x % 8, sourceGlobal.y % 8};
  glm::ivec2 destinLocal {destinGlobal.x % 8, destinGlobal.y % 8};
  int sourceSection = sourceGlobal.x / 8 + ((sourceGlobal.y / 8) * 32);
  int destinSection = destinGlobal.x / 8 + ((destinGlobal.y / 8) * 32);
  int sourceIndex = sourceLocal.x + sourceLocal.y * 8;
  int destinIndex = destinLocal.x + destinLocal.y * 8;
  float shortestDist = FLT_MAX;
  int selectedSource = INT_MAX;
  int selectedDestin = INT_MAX;
  bool failed = false;
  for (size_t i = 0; i < map.sectionMap[sourceSection].size(); i++)
  {
    int sourceJunction = map.sectionMap[sourceSection][i];
    glm::ivec2 sourceJunctionCoord;
    if (sourceSection == paths.referenceJunctions[sourceJunction].sectionA) {sourceJunctionCoord = paths.referenceJunctions[sourceJunction].nodeLocA;}
    if (sourceSection == paths.referenceJunctions[sourceJunction].sectionB) {sourceJunctionCoord = paths.referenceJunctions[sourceJunction].nodeLocB;}
    float distSourceJunction = paths.nodeSet[sourceSection][sourceIndex][convertVec2ToIndex(sourceJunctionCoord)].dist;
    for (size_t j = 0; j < map.sectionMap[destinSection].size(); j++)
    {
      int destinJunction = map.sectionMap[destinSection][j];
      glm::ivec2 destinJunctionCoord;
      if (destinSection == paths.referenceJunctions[destinJunction].sectionA) {destinJunctionCoord = paths.referenceJunctions[destinJunction].nodeLocA;}
      if (destinSection == paths.referenceJunctions[destinJunction].sectionB) {destinJunctionCoord = paths.referenceJunctions[destinJunction].nodeLocB;}
      float distDestinJunction = paths.nodeSet[destinSection][destinIndex][convertVec2ToIndex(destinJunctionCoord)].dist;
      float juncDist = paths.linker[sourceJunction][destinJunction].dist;
      float totalDist = juncDist + distSourceJunction + distDestinJunction;
      if (totalDist < shortestDist)
      {
        shortestDist = totalDist;
        selectedSource = sourceJunction;
        selectedDestin = destinJunction;
      }
    }
  }

  path returnPath;
  bool nextStartIsSecA;
  junction* endJunction = paths.linkerChains[selectedSource][selectedDestin][0];
  std::array<int, 2> cIndexPair;
  if (endJunction->sectionA == sourceSection) {cIndexPair[0] = convertVec2ToIndex(endJunction->nodeLocA);}
  else if (endJunction->sectionB == sourceSection) {cIndexPair[0] = convertVec2ToIndex(endJunction->nodeLocB);}
  cIndexPair[1] = destinIndex;
  returnPath.sections.push_back(destinSection);
  returnPath.junction.push_back(cIndexPair);
  for (size_t i = 0; i < paths.linkerSectionChain[selectedSource][selectedDestin].size(); i++)
  {
    junction* sJ = paths.linkerChains[selectedSource][selectedDestin][i];
    junction* eJ = paths.linkerChains[selectedSource][selectedDestin][i + 1];
    if (paths.linkerSectionChain[selectedSource][selectedDestin][i]== sJ->sectionA) {cIndexPair[0] = convertVec2ToIndex(sJ->nodeLocA);}
    if (paths.linkerSectionChain[selectedSource][selectedDestin][i]== sJ->sectionB) {cIndexPair[0] = convertVec2ToIndex(sJ->nodeLocB);}
    if (paths.linkerSectionChain[selectedSource][selectedDestin][i]== eJ->sectionA) {cIndexPair[1] = convertVec2ToIndex(eJ->nodeLocA);}
    if (paths.linkerSectionChain[selectedSource][selectedDestin][i]== eJ->sectionB) {cIndexPair[1] = convertVec2ToIndex(eJ->nodeLocB);}
    returnPath.junction.push_back(cIndexPair);
    returnPath.sections.push_back(paths.linkerSectionChain[selectedSource][selectedDestin][i]);
  }
  returnPath.sections.push_back(sourceSection);
  junction* startJunction = paths.linkerChains[selectedSource][selectedDestin].back();
  if (startJunction->sectionA == sourceSection) {cIndexPair[1] = convertVec2ToIndex(startJunction->nodeLocA);}
  if (startJunction->sectionB == sourceSection) {cIndexPair[1] = convertVec2ToIndex(startJunction->nodeLocB);}
  cIndexPair[0] = sourceIndex;
  returnPath.junction.push_back(cIndexPair);
}

int main(int argc, char **argv)
{
  srand (time(NULL));
  std::thread a(spinDijkstra);
  auto t1 = std::chrono::high_resolution_clock::now();
  std::thread b(run, bool(atoi(argv[1])));
  std::thread c(spinLinker);
  a.join();
  b.join();
  c.join();
  auto t2 = std::chrono::high_resolution_clock::now();
  float delta = float(std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count());
  std::cout<<std::setprecision(10)<<"Time taken: "<<delta / 1000.f<<'\n';
  t1 = std::chrono::high_resolution_clock::now();
  for (int i = 1; i < 2; i++)
  {
    for (int j = 1; j < 255; j++)
    {
      for (int x = 1; x < 255; x++)
      {
        for (int y = 1; y < 255; y++)
        {
          if (x == i && y == j) {continue;}
          glm::ivec2 start {i, j};
          glm::ivec2 dest {x, y};
          getPath(start, dest);
        }
      }
    }
  }
  t2 = std::chrono::high_resolution_clock::now();
  delta = float(std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count());
  std::cout<<std::setprecision(10)<<"Time taken: "<<delta / 1000.f<<'\n';
  long totalRoutes = long(1 * 254) * long(254 * 254);
  std::cout<<tempCount<<" out of "<<totalRoutes<<'\n';
}