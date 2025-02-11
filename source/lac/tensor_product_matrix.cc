// ------------------------------------------------------------------------
//
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright (C) 2022 by the deal.II authors
//
// This file is part of the deal.II library.
//
// Part of the source code is dual licensed under Apache-2.0 WITH
// LLVM-exception OR LGPL-2.1-or-later. Detailed license information
// governing the source code and code contributions can be found in
// LICENSE.md and CONTRIBUTING.md at the top level directory of deal.II.
//
// ------------------------------------------------------------------------

#include <deal.II/lac/tensor_product_matrix.templates.h>

DEAL_II_NAMESPACE_OPEN

namespace internal
{
  namespace TensorProductMatrixSymmetricSum
  {
#include "lac/tensor_product_matrix.inst"

  }
} // namespace internal

DEAL_II_NAMESPACE_CLOSE
