// dirent.h is used for directories
#include <iostream>
#include <stdlib.h>
#include <queue>



void MainMenu();
void RoundRobin();
void FirstComeFirstServe();
void ShortestJobFirst();
void setProcessesRR(int num);
void setProcessesFCFS(int num);
void setProcessesSJF(int num);
void FCFSSimulation(int table[][3], int totalBurst, int num);

using namespace std;