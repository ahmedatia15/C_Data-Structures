#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
#define DELETE_NODE_AT_BEGINNING

struct Node {
  uint32 NodeData;
  struct Node *LeftNodeLink;
  struct Node *RightNodeLink;
};

struct Node *DLL_1;
void Insert_Node_At_Beginning(struct Node **List, uint32 Data);
void Insert_Node_At_End(struct Node *List, uint32 Data);
void Insert_Node_After(struct Node *List, uint32 Data, uint32 position);
void Insert_Node_Before(struct Node **List, uint32 Data, uint32 position);
void Delete_Node_At_Beginning(struct Node **List);
void Delete_Node_At_End(struct Node *List);
void Delete_Node_At_Intermediate(struct Node *List, uint32 position);
void Display_All_Nodes_Forward(struct Node *List);
void Display_All_Nodes_Reverse(struct Node *List);
int main() {
  Insert_Node_At_Beginning(&DLL_1, 11);
  Display_All_Nodes_Forward(DLL_1);
  Insert_Node_At_Beginning(&DLL_1, 22);
  Display_All_Nodes_Forward(DLL_1);
  Insert_Node_At_Beginning(&DLL_1, 33);
  Display_All_Nodes_Forward(DLL_1);
  printf("----------------------\n");
  Insert_Node_At_End(DLL_1, 99);
  Display_All_Nodes_Forward(DLL_1);
  Insert_Node_At_End(DLL_1, 100);
  Display_All_Nodes_Forward(DLL_1);
  printf("----------------------\n");

  Insert_Node_After(DLL_1, 44, 2);
  Display_All_Nodes_Forward(DLL_1);
  Insert_Node_After(DLL_1, 55, 3);
  Display_All_Nodes_Forward(DLL_1);
  Insert_Node_After(DLL_1, 66, 5);
  Display_All_Nodes_Forward(DLL_1);
  printf("----------------------\n");
  Insert_Node_Before(&DLL_1, 77, 5);
  Display_All_Nodes_Forward(DLL_1);
  Insert_Node_Before(&DLL_1, 88, 1);
  Display_All_Nodes_Forward(DLL_1);
  printf("----------------------\n");
  Delete_Node_At_Beginning(&DLL_1);
  Display_All_Nodes_Forward(DLL_1);
  Delete_Node_At_Beginning(&DLL_1);
  Display_All_Nodes_Forward(DLL_1);
  printf("----------------------\n");
  Delete_Node_At_End(DLL_1);
  Display_All_Nodes_Forward(DLL_1);
  Delete_Node_At_End(DLL_1);
  Display_All_Nodes_Forward(DLL_1);
  printf("----------------------\n");
  Delete_Node_At_Intermediate(DLL_1, 2);
  Display_All_Nodes_Forward(DLL_1);
  Delete_Node_At_Intermediate(DLL_1, 3);
  Display_All_Nodes_Forward(DLL_1);

  return 0;
}

/**
 * @brief Insert node at beginning
 *
 * @param List
 * @param Data
 */
void Insert_Node_At_Beginning(struct Node **List, uint32 Data) {
  struct Node *TempNode = NULL; /* Points to the new node */

  TempNode = (struct Node *)malloc(sizeof(struct Node));
  if (NULL != TempNode) {
    TempNode->NodeData = Data;
    /* Check if the list is empty */
    if (NULL == *List) {
      TempNode->LeftNodeLink = NULL;  /* This is the only node */
      TempNode->RightNodeLink = NULL; /* This is the only node */
      (*List) = TempNode; /* Make the Head pointer points to this only node */
    } else {
      TempNode->RightNodeLink = (*List); /* Make the new node to be the head */
      TempNode->LeftNodeLink =
          NULL; /* The LeftNodeLink always NULL in the Head node */
      (*List)->LeftNodeLink = TempNode; /* This now became the second node */
      (*List) = TempNode; /* Make the Head pointer points to the new node */
    }
  } else {
    printf("Can't allocate the new node !! \n");
  }
}
/**
 * @brief Insert node at end
 *
 * @param List
 * @param Data
 */
void Insert_Node_At_End(struct Node *List, uint32 Data) {
  struct Node *TempNode = NULL;
  struct Node *NodeListCounterOne = NULL;
  TempNode = (struct Node *)malloc(sizeof(struct Node));

  if (NULL != TempNode) {
    TempNode->NodeData = Data;
    TempNode->RightNodeLink = NULL;
    NodeListCounterOne = List;
    while (NULL != NodeListCounterOne->RightNodeLink) {
      NodeListCounterOne = NodeListCounterOne->RightNodeLink;
    }
    TempNode->LeftNodeLink = NodeListCounterOne;
    NodeListCounterOne->RightNodeLink = TempNode;

  } else {
    printf("the function malloc return NULL so it can't create node \n");
  }
}
void Insert_Node_After(struct Node *List, uint32 Data, uint32 position) {
  struct Node *TempNode = NULL;
  struct Node *NodeListCounterOne = NULL;
  struct Node *NodeListCounterTwo = NULL;

  NodeListCounterOne = List;
  while (position != 1) {
    NodeListCounterOne = NodeListCounterOne->RightNodeLink;
    position--;
  }

  /*create a new node*/
  TempNode = (struct Node *)malloc(sizeof(struct Node));
  if (NULL != TempNode) {
    TempNode->NodeData = Data;
    if (NULL == NodeListCounterOne->RightNodeLink) {
      printf("you want to add a node in the end of list \n \
      plz in next time use the fun of Insert_Node_At_End\n");
      NodeListCounterOne->RightNodeLink = TempNode;
      TempNode->RightNodeLink = NodeListCounterOne;
      TempNode->RightNodeLink = NULL;
    } else {
      NodeListCounterTwo = NodeListCounterOne->RightNodeLink;
      NodeListCounterOne->RightNodeLink = TempNode;
      NodeListCounterTwo->LeftNodeLink = TempNode;
      TempNode->LeftNodeLink = NodeListCounterOne;
      TempNode->RightNodeLink = NodeListCounterTwo;
    }

  } else {
    printf("the function malloc return NULL so it can't create node \n");
  }
}
/**
 * @brief Insert node before
 *
 * @param List
 * @param Data
 * @param position
 */
void Insert_Node_Before(struct Node **List, uint32 Data, uint32 position) {
  struct Node *TempNode = NULL;
  struct Node *NodeListCounterOne = NULL;
  struct Node *NodeListCounterTwo = NULL;
  NodeListCounterOne = (*List);
  TempNode = (struct Node *)malloc(sizeof(struct Node));
  if (NULL != TempNode) {
    TempNode->NodeData = Data;
    if (1 == position) {
      TempNode->LeftNodeLink = NULL; /* This is the only node */
      TempNode->RightNodeLink = *List;
      (*List)->LeftNodeLink = TempNode;
      *List = TempNode;
    } else {
      while (position != 1) {
        NodeListCounterOne = NodeListCounterOne->RightNodeLink;
        position--;
      }
      NodeListCounterTwo = NodeListCounterOne->RightNodeLink;
      NodeListCounterOne->RightNodeLink = TempNode;
      NodeListCounterTwo->LeftNodeLink = TempNode;
      TempNode->RightNodeLink = NodeListCounterTwo;
      TempNode->LeftNodeLink = NodeListCounterOne;
    }

  } else {
    printf("the function malloc return NULL so it can't create node");
  }
}

/**
 * @brief Delete node at beginning
 *
 * @param List
 */
void Delete_Node_At_Beginning(struct Node **List) {
  struct Node *TempNode = *List;
#ifdef DELETE_NODE_AT_BEGINNING

  /* Update the head node */
  *List = (*List)->RightNodeLink;
  (*List)->LeftNodeLink = NULL;
  /* Free the first node */
  free(TempNode);
  TempNode = NULL;
#else
  *List = *List->RightNodeLink;
  free((*List).LeftNodeLink);
  (*List).LeftNodeLink = NULL;

#endif
}

/**
 * @brief Delete node at the end
 *
 * @param List
 */
void Delete_Node_At_End(struct Node *List) {
  struct Node *NodeListCounterOne = NULL;
  struct Node *NodeListCounterTwo = NULL;

  NodeListCounterOne = List;
  while (NodeListCounterOne->RightNodeLink != NULL) {
    NodeListCounterOne = NodeListCounterOne->RightNodeLink;
  }
  NodeListCounterTwo = NodeListCounterOne->LeftNodeLink;
  NodeListCounterTwo->RightNodeLink = NULL;
  free(NodeListCounterOne);
  NodeListCounterOne = NULL;
}

void Delete_Node_At_Intermediate(struct Node *List, uint32 position) {
  struct Node *NodeListCounterOne = NULL;
  struct Node *NodeListCounterTwo = NULL;

  if (1 == position) {
    printf("you want to delete mode at the beginning\n\
    please use Delete_Node_At_Beginning \n");
  } else {
    NodeListCounterOne = List;
    while (position > 1) {
      NodeListCounterOne = NodeListCounterOne->RightNodeLink;
      position--;
    }
    NodeListCounterTwo = NodeListCounterOne->LeftNodeLink;
    NodeListCounterTwo->RightNodeLink = NodeListCounterOne->RightNodeLink;
    (NodeListCounterOne->RightNodeLink)->LeftNodeLink = NodeListCounterTwo;
    /*(NodeListCounterOne->RightNodeLink) ==> the node next of the node you
     will delete it .
    ->LeftNodeLink ==> the left link of next node you will delete it
    */
    free(NodeListCounterOne);
    NodeListCounterOne = NULL;
  }
}
void Display_All_Nodes_Forward(struct Node *List) {
  struct Node *TempNode = List;

  printf("\nTraversal in forward direction ==> ");
  printf("Data : ");
  printf("%d -> ", TempNode->NodeData);
  while (TempNode->RightNodeLink != NULL) {
    TempNode = TempNode->RightNodeLink;
    printf("%d -> ", TempNode->NodeData);
  }
  if (NULL == TempNode->RightNodeLink) {
    printf("NULL");
  }
  printf("\n");
}

void Display_All_Nodes_Reverse(struct Node *List) {
  struct Node *TempNode = List;

  printf("\nTraversal in reverse direction ==> ");
  printf("Data : ");
  while (TempNode->RightNodeLink != NULL) {
    TempNode = TempNode->RightNodeLink;
  }
  while (TempNode != NULL) {
    printf("%d -> ", TempNode->NodeData);
    TempNode = TempNode->LeftNodeLink;
  }
  if (NULL == TempNode) {
    printf("NULL");
  }
  printf("\n");
}
