int controller_loadFromText(char* path , LinkedList* pArrayListServicios);
int controller_loadFromBinary(char* path , LinkedList* pArrayListServicios);
int controller_addPassenger(LinkedList* pArrayListServicios);
int controller_editPassenger(LinkedList* pArrayListServicios);
int controller_removePassenger(LinkedList* pArrayListServicios);
int controller_ListSevices(LinkedList* pArrayListServicios);
int controller_sortSevices(LinkedList* pArrayListServicios,int opciones);
int controller_saveAsText(char* path , LinkedList* pArrayListServicios);
int controller_saveAsBinary(char* path , LinkedList* pArrayListServicios);
