#define IGNORE

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>

using mpi = boost::multiprecision::int128_t;
// using mpi = boost::multiprecision::cpp_int // 任意桁

using namespace boost::numeric;
using imatrix = ublas::matrix<mpi>;
// 行列積は ublas::prod
// imatrix mat(N, M);
// mat(N, M) = 2;
