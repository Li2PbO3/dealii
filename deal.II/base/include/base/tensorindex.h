/*----------------------------   tensorindex.h     ---------------------------*/
/*      $Id$ */
#ifndef __tensorindex_H
#define __tensorindex_H
/*----------------------------   tensorindex.h     ---------------------------*/

#include <base/exceptions.h>

/**
 *
 * Rank-independent access to elements of #Tensor#.  A little class
 * template remembering #rank# integers.
 *
 * This template is implemented only for ranks between 1 and 4. If you
 * really need higher ranks, please modify the source code accordingly
 * or contact the developer.
 *
 * @author Guido Kanschat, 1999
 *
 */
template<int rank>
class TensorIndex
{
private:
				   /**
				    * Field of indices.
				    */
  unsigned int index[rank];
public:
				   /**
				    * Constructor taking #rank# indices. 
				    */
  TensorIndex(...);
  
				   /**
				    *
				    * Access operator returning index
				    * in #n#th component
				    *
				    */
  unsigned int operator () (unsigned int n) const;
  DeclException1(ExcRank, int,
		 << "Index " << arg1 << " higher than maximum " << rank-1);  
};


template<>
class TensorIndex<4>
{
private:
				   /**
				    * Field of indices.
				    */
  unsigned index[4];
public:
				   /**
				    * Constructor taking #rank# indices.
				    */
  TensorIndex(unsigned i0, unsigned i1, unsigned i2, unsigned i3)
      {
	index[0] = i0;
	index[1] = i1;
	index[2] = i2;
	index[3] = i3;
      }
  
  
				   /**
				    *
				    * Access operator returning index
				    * in #n#th component
				    *
				    */
  unsigned int operator () (unsigned int n) const
      {
	Assert(n<4, ExcRank(n));
	return index[n];

      }
  DeclException1(ExcRank, unsigned,
		 << "Index " << arg1 << " higher than maximum 3");  
};

template<>
class TensorIndex<3>
{
private:
				   /**
				    * Field of indices.
				    */
  unsigned index[3];
public:
				   /**
				    * Constructor taking #rank# indices.
				    */
  TensorIndex(unsigned i0, unsigned i1, unsigned i2)
      {
	index[0] = i0;
	index[1] = i1;
	index[2] = i2;
      }
  
  
				   /**
				    *
				    * Access operator returning index
				    * in #n#th component
				    *
				    */
  unsigned operator () (unsigned n) const
      {
	Assert(n<3, ExcRank(n));
	return index[n];

      }
  
  DeclException1(ExcRank, unsigned,
		 << "Index " << arg1 << " higher than maximum 2");  
};

template<>
class TensorIndex<2>
{
private:
				   /**
				    * Field of indices.
				    */
  unsigned index[4];
public:
				   /**
				    * Constructor taking #rank# indices.
				    */
  TensorIndex(unsigned i0, unsigned i1)
      {
	index[0] = i0;
	index[1] = i1;
      }
  
  
				   /**
				    *
				    * Access operator returning index
				    * in #n#th component
				    *
				    */
  unsigned operator () (unsigned n) const
      {
	Assert(n<2, ExcRank(n));
	return index[n];

      }
  DeclException1(ExcRank, unsigned,
		 << "Index " << arg1 << " higher than maximum 1");  
};

template<>
class TensorIndex<1>
{
private:
				   /**
				    * Field of indices.
				    */
  unsigned index[1];
public:
				   /**
				    * Constructor taking #rank# indices.
				    */
  TensorIndex(unsigned i0)
      {
	index[0] = i0;
      }
  
  
				   /**
				    *
				    * Access operator returning index
				    * in #n#th component
				    *
				    */
  unsigned operator () (unsigned n) const
      {
	Assert(n<1, ExcRank(n));
	return index[n];

      }
  DeclException1(ExcRank, unsigned,
		 << "Index " << arg1 << " higher than maximum 0");  
};

template<int rank>
inline unsigned
TensorIndex<rank>::operator() (unsigned n) const
{
  Assert(n<rank, ExcRank(n));
  return index[n];
}



/*----------------------------   tensorindex.h     ---------------------------*/
/* end of #ifndef __tensorindex_H */
#endif
/*----------------------------   tensorindex.h     ---------------------------*/
