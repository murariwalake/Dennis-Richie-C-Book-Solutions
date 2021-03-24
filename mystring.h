int mystrncmp(char *, char *, int );
char *mystrncpy(char *, char *, int);
char *mystrncat(char *, char *, int);
int strend(char *, char *);
int mystrlen(char *);
char *mystrrev(char *);
char * strcat(char *, char *);

/*first at most n charrecters of t will compare with s */
int mystrncmp(char *s, char *t, int n){
  for(; n && *s == *t; s++, t++, n--)
    if(*s == '\0' || n == 1)
    /*if s has lesser than n elements(*s == '\0') or all n elements(n == 1) are compared then it indicates
    firts at most n charrecters of t and s are same */
    return 0;
  return *s - *t;//else finally return charrecter diference
}

char *mystrncat(char *s, char *t, int n){
  char *p = s;
  /*move at the end of string  */
  while(*s++)
    ;
  s--;
  /*if all n charrs of t are copied or t has less elements than n then loop terminates */
  while(n-- && (*s++ = *t++))
    ;
  *s = '\0';//pad NULL at the end
  return p;
}

char *mystrncpy(char *s, char *t, int n){
  char *p = s;
  /*if all n(n--) charrs of t are copied or t has less elements(*s++ = *t++) than n then loop terminates
  if t has lesser elements than n value thattime (*s++ = *t++) results null, so loop terminates  */
  while(n-- && (*s++ = *t++))
    ;
  *s = '\0';//pad NULL at the end
  return p;
}

/*check wheather s contains t at the end or not */
int strend(char *s, char *t){
   s = s + mystrlen(s) - mystrlen(t); //
   for(; *s == *t; s++, t++)
    if(*s == '\0') // if all charrecters compared then return 1
      return 1;

   return 0;

}
/*returns the lenth of s  */
int mystrlen(char *s){
  char *p = s;
  while(*s++) //at the end of the string value of *s becomes zero
    ;
    s--;//s pointing to end of the string that is '\0'
  return s - p;
}
/*returns the pointer to the reversed s */
char *mystrrev(char *s){
  char *p = mystrlen(s) - 1;
  char *start = s;
  for(; s < p; s++, p++){
    char temp = *s;
    *s = *p;
    *p = temp;
  }
  return start;
}

char * strcat(char *s, char *t){
  char *p = s;
  while(*s++)  //At the end of string *s value becomes NULL loop terminates
    ;
  s--; //s starts to points at the end of charrecter that is '\0'
  while(*s++ = *t++)  //copy char from t to s untill last charrecter including '\0'
    ;
  return p;//p pinting to first charrecter of s
}
