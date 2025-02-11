// ------------------------------------------------------------------------
//
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright (C) 2000 - 2023 by the deal.II authors
//
// This file is part of the deal.II library.
//
// Part of the source code is dual licensed under Apache-2.0 WITH
// LLVM-exception OR LGPL-2.1-or-later. Detailed license information
// governing the source code and code contributions can be found in
// LICENSE.md and CONTRIBUTING.md at the top level directory of deal.II.
//
// ------------------------------------------------------------------------


#include <deal.II/fe/fe_tools.templates.h>

DEAL_II_NAMESPACE_OPEN


namespace FETools
{
  namespace internal
  {
    namespace FEToolsAddFENameHelper
    {
      std::shared_mutex fe_name_map_lock;
    }
  } // namespace internal
} // namespace FETools


/*-------------- Explicit Instantiations -------------------------------*/
#include "fe/fe_tools.inst"

// these do not fit into the templates of the dimension in the inst file
namespace FETools
{
  // Specializations for FE_Q.
  template <>
  std::unique_ptr<FiniteElement<1, 1>>
  FEFactory<FE_Q<1, 1>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_Q<1>>(quad);
  }

  template <>
  std::unique_ptr<FiniteElement<2, 2>>
  FEFactory<FE_Q<2, 2>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_Q<2>>(quad);
  }

  template <>
  std::unique_ptr<FiniteElement<3, 3>>
  FEFactory<FE_Q<3, 3>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_Q<3>>(quad);
  }

  // Specializations for FE_Q_DG0.
  template <>
  std::unique_ptr<FiniteElement<1, 1>>
  FEFactory<FE_Q_DG0<1, 1>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_Q_DG0<1>>(quad);
  }

  template <>
  std::unique_ptr<FiniteElement<2, 2>>
  FEFactory<FE_Q_DG0<2, 2>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_Q_DG0<2>>(quad);
  }

  template <>
  std::unique_ptr<FiniteElement<3, 3>>
  FEFactory<FE_Q_DG0<3, 3>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_Q_DG0<3>>(quad);
  }

  // Specializations for FE_Q_Bubbles.
  template <>
  std::unique_ptr<FiniteElement<1, 1>>
  FEFactory<FE_Q_Bubbles<1, 1>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_Q_Bubbles<1>>(quad);
  }

  template <>
  std::unique_ptr<FiniteElement<2, 2>>
  FEFactory<FE_Q_Bubbles<2, 2>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_Q_Bubbles<2>>(quad);
  }

  template <>
  std::unique_ptr<FiniteElement<3, 3>>
  FEFactory<FE_Q_Bubbles<3, 3>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_Q_Bubbles<3>>(quad);
  }

  // Specializations for FE_DGQArbitraryNodes.
  template <>
  std::unique_ptr<FiniteElement<1, 1>>
  FEFactory<FE_DGQ<1>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_DGQArbitraryNodes<1>>(quad);
  }

  template <>
  std::unique_ptr<FiniteElement<1, 2>>
  FEFactory<FE_DGQ<1, 2>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_DGQArbitraryNodes<1, 2>>(quad);
  }

  template <>
  std::unique_ptr<FiniteElement<1, 3>>
  FEFactory<FE_DGQ<1, 3>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_DGQArbitraryNodes<1, 3>>(quad);
  }

  template <>
  std::unique_ptr<FiniteElement<2, 2>>
  FEFactory<FE_DGQ<2>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_DGQArbitraryNodes<2>>(quad);
  }

  template <>
  std::unique_ptr<FiniteElement<2, 3>>
  FEFactory<FE_DGQ<2, 3>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_DGQArbitraryNodes<2, 3>>(quad);
  }

  template <>
  std::unique_ptr<FiniteElement<3, 3>>
  FEFactory<FE_DGQ<3>>::get(const Quadrature<1> &quad) const
  {
    return std::make_unique<FE_DGQArbitraryNodes<3>>(quad);
  }

  template std::vector<unsigned int>
  hierarchic_to_lexicographic_numbering<0>(unsigned int);

  template std::vector<unsigned int>
  lexicographic_to_hierarchic_numbering<0>(unsigned int);
} // namespace FETools

DEAL_II_NAMESPACE_CLOSE
