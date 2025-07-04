#ifndef MUMPS_HPP
#define MUMPS_HPP

#include <dmumps_c.h>

constexpr int JOB_INIT{-1};
constexpr int JOB_END{-2};
constexpr int USE_COMM_WORLD{-987654};

template <typename T>
struct MUMPS_STRUC_TRAIT;

template <>
struct MUMPS_STRUC_TRAIT<double>
{
	using MUMPS_STRUC_TYPE = DMUMPS_STRUC_C;
};

template <typename T>
class MUMPS_STRUC_C;

template <typename T>
void mumps_c(MUMPS_STRUC_C<T> &mumps_par);

template <typename T>
class MUMPS_STRUC_C
{
	friend void mumps_c<>(MUMPS_STRUC_C<T> &mumps_par);

public:
	const auto &INFOG(int i) const { return id_.infog[i - 1]; }

	auto &ICNTL(int i) { return id_.icntl[i - 1]; }

	auto &n() { return id_.n; }

	auto &nnz() { return id_.nnz; }

	auto &irn() { return id_.irn; }

	auto &jcn() { return id_.jcn; }

	auto &a() { return id_.a; }

	auto &rhs() { return id_.rhs; }

	auto &job() { return id_.job; }

	auto &comm() { return id_.comm_fortran; }

	auto &par() { return id_.par; }

	auto &sym() { return id_.sym; }

private:
	typename MUMPS_STRUC_TRAIT<T>::MUMPS_STRUC_TYPE id_;
};

template <>
inline void mumps_c(MUMPS_STRUC_C<double> &mumps_par)
{
	dmumps_c(&(mumps_par.id_));
}

#endif //! MUMPS_HPP