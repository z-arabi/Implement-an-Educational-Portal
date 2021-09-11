/* This is called a "forward declaration".  We use it to tell the compiler that
   the identifier "B" will from now on stand for a class, and this class will be
   defined later.  We will not be able to make any use of "B" before it has been
   defined, but we will at least be able to declare pointers to it. */
class B;

class A
{
    public:
    /* We cannot have a field of type "B" here, because it has not yet been
       defined. However, with the forward declaration we have told the compiler
       that "B" is a class, so we can at least have a field which is a pointer 
       to "B". */
    B* pb; 
    int id=10;
};