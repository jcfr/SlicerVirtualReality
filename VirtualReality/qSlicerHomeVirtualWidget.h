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

#ifndef __qSlicerHomeVirtualWidget_h
#define __qSlicerHomeVirtualWidget_h

// Qt includes
#include <QWidget>
#include <QDialog>

namespace dimensions
{
  const int height = 688;
  const int width  = 980;
}

class qSlicerHomeVirtualWidget : public QWidget
{
  Q_OBJECT
public:
  qSlicerHomeVirtualWidget(QWidget *parent = 0);
  ~qSlicerHomeVirtualWidget();
public slots:

};


#endif
