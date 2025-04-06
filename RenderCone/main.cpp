#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);   // ��ʼ��OpenGL��Ⱦ���
VTK_MODULE_INIT(vtkInteractionStyle);  // ��ʼ���������

#include <iostream>

#include <vtkConeSource.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>


int main()
{
    std::cout << __FUNCTION__ << std::endl;

    auto cone = vtkCylinderSource::New();
    cone->SetHeight(5.0);
    cone->SetRadius(2.0);
    cone->SetResolution(50);

    vtkPolyDataMapper* mapper = vtkPolyDataMapper::New();
    mapper->SetInputConnection(cone->GetOutputPort());
    mapper->ScalarVisibilityOff();

    auto coneActor = vtkActor::New();
    coneActor->SetMapper(mapper);
    coneActor->GetProperty()->SetColor(1.0, 0.0, 0.0);

    auto data = coneActor->GetPosition();
    auto render = vtkRenderer::New();
    render->AddActor(coneActor);
    render->SetBackground(0.2, 0.3, 0.4);  // ���ñ���ɫ


    auto window = vtkRenderWindow::New(); 
    window->AddRenderer(render);
    window->SetSize(800, 600);  // ���ô��ڳߴ�

    // ��������ʼ��
    auto interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow(window);
    interactor->Initialize();  // �����ʼ��
    interactor->Start();       // �����¼�ѭ��
    return 0;
}