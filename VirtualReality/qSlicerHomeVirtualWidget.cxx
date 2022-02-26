/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

#include "qSlicerHomeVirtualReality.h"

// Qt includes
#include <QAction>
#include <QButtonGroup>
#include <QDebug>
#include <QDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QPushButton>
#include <QSettings>
#include <QSlider>
#include <QSpacerItem>
#include <QtPlugin>
#include <QVBoxLayout>
#include <QWidget>

//-----------------------------------------------------------------------------
//   qSlicerHomeVirtualWidget Methods

//-----------------------------------------------------------------------------
qSlicerHomeVirtualWidget::qSlicerHomeVirtualWidget(QWidget *parent)
{
  this->minimumHeight(650);
  this->minimumWidth(980);
  this->resize(dimensions::height, dimensions::width);

  //Create all the Qlabels 
  QLabel *flySpeedLabel      = new QLabel("Fly Speed:", this);
  QLabel *magnificationLabel = new QLabel("Magnification:", this);
  QLabel *motionSenLabel     = new QLabel("Motion Sensitivity:", this;
  QLabel *lightingLabel      = new QLabel("Lighting:", this);

  //Create all the push buttons
  QPushButton *syncView = new QPushButton("Sync view to Reference View", this);
  QPushButton *magnificationButton1 = new QPushButton("0.5x", this);
  QPushButton *magnificationButton2 = new QPushButton("1x",   this);
  QPushButton *magnificationButton3 = new QPushButton("2x",   this);
  QPushButton *magnificationButton4 = new QPushButton("40x",  this);
  QPushButton *twoSidedLighting     = new QPushButton("Two-sided Lighting", this);
  QPushButton *backLighting         = new QPushButton("Back Lighting", this);

  //create all sliders
  QSlider *flySpeedSlider  = new QSlider(Qt::Horizontal, this);
  QSlider *motionSenSlider = new QSlider(Qt::Horizontal, this);
  
  //create the layouts for the UI 
  QFormLayout  *menuLayout                = new QFormLayout(this);
  QHBoxLayout  *magnificationButtonLayout = new QHBoxLayout(this);
  QHBoxLayout  *lightingButtonLayout      = new QHBoxLayout(this);
  
  //place Qwidgets in appropriate layouts
  magnificationButtonLayout->addWidget(magnificationButton1);
  magnificationButtonLayout->addWidget(magnificationButton2);
  magnificationButtonLayout->addWidget(magnificationButton3);
  magnificationButtonLayout->addWidget(magnificationButton4);
  lightingButtonLayout->addWidget(twoSidedLighting);
  lightingButtonLayout->addWidget(backLighting);

  //set up the main form layout
  menuLayout->addRow(flySpeedLabel, flySpeedSlider);
  menuLayout->addRow(magnificationLabel, magnificationButtonLayout);
  menuLayout->addRow(motionSenLabel, motionSenSlider);
  menuLayout->addRow(lightingLabel, lightingButtonLayout);

  //spacing and positioning
  menuLayout->setHorizontalSpacing(20);  
  menuLayout->setVerticleSpacing(99); 
}
//---------------------------------------------------------------
qSlicerHomeVirtualWidget::~qSlicerHomeVirtualWidget()
{
};