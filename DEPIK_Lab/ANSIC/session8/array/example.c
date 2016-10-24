typedef struct node_s
{
  int data;
  struct node_s *link;
}node_t;
node_t *t;
node_t *y;
main()
{
   node_t *p; 
   node_t *q; 
   node_t *r;
printf("\naddress of p=%u",&p); 
printf("\nvalue of p=%u",p); 
printf("\naddress of q=%u",&q); 
printf("\nvalue of q=%u",q); 
printf("\naddress of r=%u",&r); 
printf("\nvalue of r=%u",r); 
printf("\naddress of t=%u",&t); 
printf("\nvalue of t=%u",t);
printf("\naddress of y=%u",&y); 
printf("\nvalue of y=%u",y);
printf("\naddress of node_t=%u",node_t); 
} 
