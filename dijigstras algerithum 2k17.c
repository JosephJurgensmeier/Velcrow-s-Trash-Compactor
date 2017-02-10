const int NODE_COUNT = 74;

struct path
{
	int destination;
	int pathDistanceVar;
	int pathDirectionVar ;// -1 is a left turn. 0 is straight. +1 is a right turn.
};

struct node
{
	struct path path1;
	struct path path2;
	int totalDistance ;
	int explorationFlag  ;
	int parent ;
};

// GLOBAL VARIABLES //
struct node NODE_LIST[100];

void setNodeExplorationFlag(int nodeID, int flagState)//sets flag on node
{
	NODE_LIST[nodeID].explorationFlag = flagState;
}

void setNodeDistance(int nodeID, int distance)
{
	NODE_LIST[nodeID].totalDistance = distance;
	//writeDebugStreamLine("Set node %d distance to %d: (%d)",nodeID,distance,NODE_LIST[nodeID].totalDistance);
}

int findNearest() //function finds nearest node and returns its ID
{
	int nearestNode = 0;
	int shortestDistance = 0;
	int i;
	for ( i = 1; i <= NODE_COUNT; i++)
	{
		if (NODE_LIST[i].explorationFlag == 0 && (NODE_LIST[i].totalDistance <  shortestDistance || nearestNode == 0))
		{
			shortestDistance = NODE_LIST[i].totalDistance;
			nearestNode = i;
		}
	}
	return nearestNode;
}

void findChildren(int nearest) //adds child nodes to unexplored list
{
	int childNode = NODE_LIST[nearest].path1.destination;
	int pathDistance = NODE_LIST[nearest].path1.pathDistanceVar;
	for(int i = 0; i < 2; i++) // loop twice
	{
		if(NODE_LIST[childNode].explorationFlag == 1)//explored
		{
			//Do nothing
		}
		else if(NODE_LIST[childNode].explorationFlag == 0)//unexplored
		{
			if(NODE_LIST[childNode].totalDistance > NODE_LIST[nearest].totalDistance + pathDistance)
			{
				//writeDebugStreamLine("Nearest distance = %d",NODE_LIST[nearest].totalDistance);
				//writeDebugStreamLine("Path distance = %d",pathDistance);
				setNodeDistance(childNode, NODE_LIST[nearest].totalDistance + pathDistance);
				//writeDebugStreamLine("Tried to change node %d distance to %d: (%d)",childNode,NODE_LIST[nearest].totalDistance + pathDistance,NODE_LIST[childNode].totalDistance);
				//NODE_LIST[childNode].totalDistance = NODE_LIST[nearest].totalDistance + pathDistance;
				NODE_LIST[childNode].parent = nearest;
			}
		}
		else//unknown
		{
			setNodeExplorationFlag(childNode, 0);
			//writeDebugStreamLine("Nearest distance = %d",NODE_LIST[nearest].totalDistance);
			//writeDebugStreamLine("Path distance = %d",pathDistance);
			setNodeDistance(childNode, NODE_LIST[nearest].totalDistance + pathDistance);
			//writeDebugStreamLine("Tried to change node %d distance to %d: (%d)",childNode,NODE_LIST[nearest].totalDistance + pathDistance,NODE_LIST[childNode].totalDistance);
			//NODE_LIST[childNode].totalDistance = NODE_LIST[nearest].totalDistance + pathDistance;
			NODE_LIST[childNode].parent = nearest;
		}

		if(NODE_LIST[nearest].path1 != NODE_LIST[nearest].path2) // if second path exists, loop again on it
		{
			childNode = NODE_LIST[nearest].path2.destination;
			pathDistance = NODE_LIST[nearest].path2.pathDistanceVar;
		}
		else // no second path, so skip second loop
		{
			return;
		}
	}
}



void addPath(int source, int destination, int pathDistance,int pathDirection) //Function that creates paths between nodes
{

	if(NODE_LIST[source].path1 == NODE_LIST[source].path2) // if paths are equal, then neither is used yet
	{
		NODE_LIST[source].path1.destination = destination;
		NODE_LIST[source].path1.pathDistanceVar = pathDistance;
		NODE_LIST[source].path1.pathDirectionVar = pathDirection;
	}
	else
	{
		NODE_LIST[source].path2.destination = destination;
		NODE_LIST[source].path2.pathDistanceVar = pathDistance;
		NODE_LIST[source].path2.pathDirectionVar = pathDirection;
	}
}

void makeMap()
{
	addPath(1,62,173,-1);
	addPath(2,1,127,0);
	addPath(2,26,61,-1);
	addPath(3,2,155,0);
	addPath(3,12,28,-1);
	addPath(4,3,128,0);
	addPath(4,13,28-1);
	addPath(5,4,88,0);
	addPath(5,14,28,-1);
	addPath(6,5,96,0);
	addPath(6,15,28,-1);
	addPath(7,3,50,-1);
	addPath(8,4,32,-1);
	addPath(9,6,50,-1);
	addPath(10,6,122,-1);
	addPath(11,26,111,111);//
	addPath(12,18,63,-1);
	addPath(12,28,54,0);
	addPath(13,20,44,-1);
	addPath(13,27,30,0);
	addPath(14,22,95,);
	addPath(14,30,54);
	addPath(15,23,62);
	addPath(15,31,54);
	addPath(16,11,111);//
	addPath(16,17,111);//
	addPath(17,18,63);
	addPath(17,28,54);
	addPath(18,7,28);
	addPath(18,19,63);
	addPath(19,20,44);
	addPath(19,27,30);
	addPath(20,8,28);
	addPath(20,21,44);
	addPath(21,22,95);
	addPath(21,30,54);
	addPath(22,23,62);
	addPath(22,31,54);
	addPath(23,9,30);
	addPath(24,7,28);
	addPath(24,19,63);
	addPath(25,9,30);
	addPath(26,41,42);
	addPath(26,16,111);//
	addPath(27,29,111);//
	addPath(28,32,64);
	addPath(28,43,44);
	addPath(29,34,111);//
	addPath(29,40,111);//
	addPath(30,35,64);
	addPath(30,45,43);
	addPath(31,37,41);
	addPath(31,46,48);
	addPath(32,42,44);
	addPath(33,32,64);
	addPath(33,43,44);
	addPath(34,24,54);
	addPath(34,33,62);
	addPath(35,29,111);//
	addPath(36,35,64);
	addPath(36,45,43);
	addPath(37,36,53);
	addPath(38,24,54);
	addPath(38,33,62);
	addPath(39,36,53);
	addPath(40,29,111);//
	addPath(40,44,111);//
	addPath(41,39,60);
	addPath(41,47,158);
	addPath(42,47,52);
	addPath(43,48,62);
	addPath(43,63,44);
	addPath(44,50,88);
	addPath(44,64,44);
	addPath(45,51,53);
	addPath(45,65,44);
	addPath(46,53,67);
	addPath(46,66,44);
	addPath(47,63,44);
	addPath(47,48,62);
	addPath(48,38,44);
	addPath(48,49,63);
	addPath(49,64,44);
	addPath(49,50,88);
	addPath(50,65,44);
	addPath(50,51,53);
	addPath(51,39,44);
	addPath(51,52,40);
	addPath(52,66,44);
	addPath(52,53,67);
	addPath(53,25,98);
	addPath(53,54,53);
	addPath(54,10,128);
	addPath(55,38,44);
	addPath(55,49,63);
	addPath(56,50,31);
	addPath(57,39,43);
	addPath(57,52,40);
	addPath(58,25,98);
	addPath(58,54,53);
	addPath(59,10,128);
	addPath(60,74,111);//
	addPath(61,74,111);//
	addPath(62,67,88);
	addPath(74,69,184); //accidently named two different intersections 62. fixed by changing one to 74
	addPath(63,69,50);
	addPath(64,70,31);
	addPath(65,71,41);
	addPath(66,72,55);
	addPath(67,61,111);//
	addPath(67,68,71);
	addPath(68,69,184);
	addPath(69,55,44);
	addPath(69,70,108);
	addPath(70,56,44);
	addPath(70,71,98);
	addPath(71,57,44);
	addPath(71,72,109);
	addPath(72,58,44);
	addPath(72,73,53);
	addPath(73,59,44);

}

void debugPrintRoute(int endNode)
{
	int current = endNode;
	int nodeList[NODE_COUNT];
	int i;
	for(i = 0; current != 0; i++)
	{
		nodeList[i] = current;
		current = NODE_LIST[current].parent;
	}

	for(i--;i > 0; i--)
	{
		writeDebugStreamLine("go from node %d to node %d", nodeList[i],nodeList[i-1]);

	}
	writeDebugStreamLine("done");
	/*
	for(i=0; i < NODE_COUNT; i++)
	{
		writeDebugStreamLine("Distance of node %d is %d",i,NODE_LIST[i].totalDistance);
	}
	*/
}

void findRoute(int startNode,int endNode)
{
	// initialize unexplored list with start node
	// initialize flag to unknown
	int i;
	for(i = 1; i <= NODE_COUNT; i++)
	{
		setNodeDistance(i,15000);
		setNodeExplorationFlag(i, -1);
		NODE_LIST[i].parent = 0;
	}

	setNodeExplorationFlag(startNode, 0);// sets start node to unexplored
	setNodeDistance(startNode, 0);

	int debugCount = 0; // count number of nodes explored
	while(true)
	{
		debugCount++;

		// find nearest unexplored node
		// use list of distances from start to each node to compare and find nearest
		int nearest = findNearest();
		if(nearest == 0)
		{
			//find nearest fouldn't find nearest
			writeDebugStreamLine("dang it! (%d nodes explored)",debugCount);
			return;
		}
		if(nearest == endNode)
		{
			// if it is the end node, then SUCCESS!
			writeDebugStreamLine("success");
			return;
		}

		// add its child nodes to the unexplored list, if they are already there, then update their distances if shorter
		findChildren(nearest);
		setNodeExplorationFlag(nearest, 1);// removes node from unexplored list

	}
}

/*void checkMap()
{
	for(int i=0; i<=NODE_COUNT; i++)
	{
		writeDebugStreamLine("Checking node %d:",i);
		writeDebugStreamLine("\ttotalDistance = %d",NODE_LIST[i].totalDistance);
		writeDebugStreamLine("\texplorationFlag = %d",NODE_LIST[i].explorationFlag);
		writeDebugStreamLine("\tPath1:");
		writeDebugStreamLine("\t\tdestination = %d",NODE_LIST[i].path1.destination);
		writeDebugStreamLine("\t\tpathDistanceVar = %d",NODE_LIST[i].path1.pathDistanceVar);
		writeDebugStreamLine("\tPath2:");
		writeDebugStreamLine("\t\tdestination = %d",NODE_LIST[i].path2.destination);
		writeDebugStreamLine("\t\tpathDistanceVar = %d",NODE_LIST[i].path2.pathDistanceVar);
		writeDebugStreamLine("");
	}
}
*/
task main()
{
	makeMap();
	//checkMap();
	findRoute(1, 10);
	debugPrintRoute(10);
}
