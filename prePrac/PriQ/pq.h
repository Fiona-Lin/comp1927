// A priority Queue ADT interface

typedef struct pqImp * PriQ;

// Core operations 
PriQ initPriQ(void); 
void insert(PriQ q, Item i); 
Item delete(PriQ q); 

// Useful operations 
int sizePriQ(PriQ q); 
void change(PriQ q, Key k, Item i);
void deleteKey(PriQ q, Key k); 
PriQ join(PriQ q1, PriQ q2); 
