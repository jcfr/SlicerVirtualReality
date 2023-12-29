/*==============================================================================

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through CANARIE's Research Software Program, and Cancer
  Care Ontario.

==============================================================================*/

#ifndef vtkVirtualRealityViewOpenXRInteractor_h
#define vtkVirtualRealityViewOpenXRInteractor_h

// VR MRMLDM includes
#include "vtkSlicerVirtualRealityModuleMRMLDisplayableManagerExport.h"
#include "vtkVirtualRealityComplexGestureRecognizer.h"

// VTK Rendering/OpenXR includes
#include <vtkOpenXRRenderWindowInteractor.h>

// VTK includes
#include <vtkNew.h>


class VTK_SLICER_VIRTUALREALITY_MODULE_MRMLDISPLAYABLEMANAGER_EXPORT vtkVirtualRealityViewOpenXRInteractor
  : public vtkOpenXRRenderWindowInteractor
{
public:
  static vtkVirtualRealityViewOpenXRInteractor *New();
  vtkTypeMacro(vtkVirtualRealityViewOpenXRInteractor,vtkOpenXRRenderWindowInteractor);

  ///@{
  /// Define Slicer specific heuristic for handling complex gestures.
  virtual void HandleComplexGestureEvents(vtkEventData* ed) override
  {
    this->ComplexGestureRecognizer->HandleComplexGestureEvents(ed);
  }
  virtual void RecognizeComplexGesture(vtkEventDataDevice3D* edata) override
  {
    this->ComplexGestureRecognizer->RecognizeComplexGesture(edata);
  }
  ///@}

protected:
  vtkNew<vtkVirtualRealityComplexGestureRecognizer> ComplexGestureRecognizer;

private:
  vtkVirtualRealityViewOpenXRInteractor()
  {
    this->ComplexGestureRecognizer->SetInteractor(this);
  }
  ~vtkVirtualRealityViewOpenXRInteractor() override = default;

  vtkVirtualRealityViewOpenXRInteractor(const vtkVirtualRealityViewOpenXRInteractor&) = delete;
  void operator=(const vtkVirtualRealityViewOpenXRInteractor&) = delete;
};

#endif
