#pragma once

#include "Material.h"

class SinglePhaseFluidProperties;

/**
 * Computes Reynolds number as a material property
 */
class ADReynoldsNumberMaterial : public Material
{
public:
  ADReynoldsNumberMaterial(const InputParameters & parameters);

protected:
  virtual void computeQpProperties();

  /// Reynolds number property name
  const MaterialPropertyName & _Re_name;

  /// Density of the phase
  const ADMaterialProperty<Real> & _rho;

  /// Velocity of the phase
  const ADMaterialProperty<Real> & _vel;

  /// Hydraulic diameter
  const MaterialProperty<Real> & _D_h;

  /// Dynamic viscosity of the phase
  const ADMaterialProperty<Real> & _mu;

  /// Reynolds
  ADMaterialProperty<Real> & _Re;

public:
  static InputParameters validParams();
};