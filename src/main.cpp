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

bool done = false;
bool running = false;
int mapsDone = 0;
int totalMaps = 0;
bool etaDirty = false;
enum directionEnum {d0 = 9, dN = 1, dNE = 2, dE = 3, dSE = 4, dS = 5, dSW = 6, dW = 7, dNW = 8, dNone = 0, dNoRoute = 10};


void spin()
{
  while (!running)
  {
    nanosleep((const struct timespec[]){{0, 25000L}}, NULL);
  }
  auto t1 = std::chrono::high_resolution_clock::now();
  auto t2 = std::chrono::high_resolution_clock::now();
  float delta;
  int percent = 0;
  std::__cxx11::string tString;
  while(!done)
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

    std::cout << "\rCalculating Dijkstra ⠁ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% done"<<std::setprecision(6)<<", time remaining: "<<tString<<')'<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (done) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rCalculating Dijkstra ⠂ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% done"<<std::setprecision(6)<<", time remaining: "<<tString<<')'<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (done) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rCalculating Dijkstra ⠄ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% done"<<std::setprecision(6)<<", time remaining: "<<tString<<')'<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (done) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rCalculating Dijkstra ⡀ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% done"<<std::setprecision(6)<<", time remaining: "<<tString<<')'<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (done) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rCalculating Dijkstra ⢀ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% done"<<std::setprecision(6)<<", time remaining: "<<tString<<')'<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (done) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rCalculating Dijkstra ⠠ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% done"<<std::setprecision(6)<<", time remaining: "<<tString<<')'<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (done) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rCalculating Dijkstra ⠐ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% done"<<std::setprecision(6)<<", time remaining: "<<tString<<')'<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (done) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
    std::cout << "\rCalculating Dijkstra ⠈ (running for "<<std::setprecision(10)<< delta<< "s, "<<percent<<"% done"<<std::setprecision(6)<<", time remaining: "<<tString<<')'<<std::flush;
    for (size_t i = 0; i < 100; i++)
    {
      if (done) {std::cout<<"\nDijkstra complete.\nCrunching paths...\n"<<std::flush; return;}
      nanosleep((const struct timespec[]){{0, 1250000L}}, NULL);
    }
  }
}

struct flowStorage
{
  typedef std::array<int, 64> singleFlow;
  typedef std::array<singleFlow, 64> sectionFlow;
  typedef std::vector<sectionFlow> allFlow;
  singleFlow currentFlow;
  sectionFlow currentSectionFlow;
  allFlow allFlows;
};

struct node
{
  bool unvisited = true;
  bool enabled = true;
  bool isRoute = false;
  glm::vec2 loc;
  int locX() const;
  int locY() const;
  float dist = INT_MAX;
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

flowStorage flows;

float vectorLength(glm::vec2 a)
{
  float dist = sqrt(pow(a.x, 2) + pow(a.y, 2));
  return dist;
}

std::vector<node> dijkstra(int sectionNo, int sourceX, int sourceY)
{
  running = true;
  auto t1 = std::chrono::high_resolution_clock::now();
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
    static int count = 0;
    if (numUnvisitedNodes == startNumRemNodes) {count = 0;}
    count++;
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

  auto t2 = std::chrono::high_resolution_clock::now();
  float deltaCalc = float(std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count());
}

std::array<std::vector<node>, 64> calculateMap(int sectionNo)
{
  std::array<std::vector<node>, 64> allNodes;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      allNodes[j * 8 + i] = dijkstra(sectionNo, i, j);
      mapsDone++;
      etaDirty = true;
    }
  }
  return allNodes;
}

flowStorage::singleFlow generateFlow(std::vector<node> nodes, int goalX, int goalY)
{
  flowStorage::singleFlow flow;
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
    else if (nodes[i].dist == INT_MAX)
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
        switch (flows.allFlows[section][flowInSection][y * 8 + x])
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

void run(bool printFlag)
{
  totalMaps = 8 * 8 * 1024;
  std::array<std::array<std::vector<node>, 64>, 1024> nodeSet;
  for (int i = 0; i < 1024; i++) {nodeSet[i] = calculateMap(i);}
  done = true;
  for (int section = 0; section < 1024; section++)
  {
    int x = 0;
    int y = 0;
    for (int flowInSection = 0; flowInSection < 64; flowInSection++)
    {
      x = flowInSection % 8;
      if (flowInSection != 0 && x == 0) {y++;}
      if (nodeSet[section][flowInSection][flowInSection].enabled) {flows.currentFlow = generateFlow(nodeSet[section][flowInSection], x, y);}
      else {flows.currentFlow = flowStorage::singleFlow();}
      flows.currentSectionFlow[flowInSection] = flows.currentFlow;
    }
    flows.allFlows.push_back(flows.currentSectionFlow);
  }
  if(printFlag) {printFlows();}
}

int main(int argc, char **argv)
{
  std::thread a (spin);
  auto t1 = std::chrono::high_resolution_clock::now();
  std::thread b (run, bool(atoi(argv[1])));
  a.join();
  b.join();
  auto t2 = std::chrono::high_resolution_clock::now();
  float delta = float(std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count());
  std::cout<<std::setprecision(10)<<"Time taken: "<<delta / 1000.f<<'\n';
}