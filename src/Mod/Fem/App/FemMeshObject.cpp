/***************************************************************************
 *   Copyright (c) 2008 J�rgen Riegel (juergen.riegel@web.de)              *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#include "PreCompiled.h"

#ifndef _PreComp_
#endif

#include "FemMeshObject.h"
#include <App/DocumentObjectPy.h>
#include <Base/Placement.h>

using namespace Fem;
using namespace App;

PROPERTY_SOURCE(Fem::FemMeshObject, App::GeoFeature)


FemMeshObject::FemMeshObject()
{
    ADD_PROPERTY_TYPE(FemMesh,(), "FEM Mesh",Prop_None,"FEM Mesh object");
}

FemMeshObject::~FemMeshObject()
{
}

short FemMeshObject::mustExecute(void) const
{
    return 0;
}

PyObject *FemMeshObject::getPyObject()
{
    if (PythonObject.is(Py::_None())){
        // ref counter is set to 1
        PythonObject = Py::Object(new DocumentObjectPy(this),true);
    }
    return Py::new_reference_to(PythonObject); 
}

void FemMeshObject::onChanged(const Property* prop)
{
    App::GeoFeature::onChanged(prop);
}
