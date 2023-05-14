#include "Editor.h"
#include "EditorScene.h"

#include "layers/PELayer.h"
#include "layers/UILayer.h"

EditorScene::EditorScene()
{
	backcolor = glm::vec3(0.2f, 0.2f, 0.2f);
	Entity* testObject = new Entity("test");
	testObject->AddComponent(new CubeRenderer(glm::vec4(1.0f, 0.5f, 0.31f, 1.0f)));
	AddEntityToScene(testObject);
}

EditorScene::~EditorScene()
{
}

void EditorScene::OnStart()
{
	AddLayer(new UILayer());
	AddLayer(new PELayer());
}

void EditorScene::OnStop()
{
}

void EditorScene::OnUpdate()
{
	const float dt = Application::GetDT();
	if (Input::IsKeyPressed(KEY_W))
	{
		camera->position.x += 5 * dt * camera->GetFront().x;
		camera->position.z += 5 * dt * camera->GetFront().z;
	}
	if (Input::IsKeyPressed(KEY_A))
	{
		camera->position.x += 5 * dt * camera->GetFront().z;
		camera->position.z -= 5 * dt * camera->GetFront().x;

	}
	if (Input::IsKeyPressed(KEY_S))
	{
		camera->position.x -= 5 * dt * camera->GetFront().x;
		camera->position.z -= 5 * dt * camera->GetFront().z;

	}
	if (Input::IsKeyPressed(KEY_D))
	{
		camera->position.x -= 5 * dt * camera->GetFront().z;
		camera->position.z += 5 * dt * camera->GetFront().x;

	}
	if (Input::IsKeyPressed(KEY_SPACE))
		camera->position.y += 5 * dt;
	if (Input::IsKeyPressed(KEY_C))
		camera->position.y -= 5 * dt;
}

void EditorScene::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.dispatch<KeyPressedEvent>(BIND_EVENT_FN(EditorScene::KeyPressed));
	dispatcher.dispatch<MouseScrolledEvent>(BIND_EVENT_FN(EditorScene::MouseScrolled));
	dispatcher.dispatch<WindowFocusEvent>(BIND_EVENT_FN(EditorScene::WindowFocus));
	dispatcher.dispatch<WindowLostFocusEvent>(BIND_EVENT_FN(EditorScene::WindowLostFocus));
}

bool EditorScene::KeyPressed(KeyPressedEvent& event) const
{
	if (event.getKeyCode() == KEY_LEFT_ALT)
	{
		Application::GetWindow()->CursorEnabled(!Application::GetWindow()->IsCursorEnabled());
	}
	if (event.getKeyCode() == KEY_ESCAPE)
	{
		Application::GetWindow()->CursorEnabled(true);
	}
	return false;
}

bool EditorScene::MouseScrolled(MouseScrolledEvent& event) const
{
	if (event.GetYOffset() < 0 && camera->fov > 0.01f)
	{
		camera->fov += event.GetYOffset() / 5;
		return true;
	}
	if (camera->fov < 0.01f) camera->fov = 0.01f;
	if (event.GetYOffset() > 0 && camera->fov < 120.0f)
	{
		camera->fov += event.GetYOffset() / 5;
		return true;
	}
	return false;
}

bool EditorScene::WindowFocus(WindowFocusEvent& event) const
{
	Application::GetWindow()->CursorEnabled(false);
	return true;
}

bool EditorScene::WindowLostFocus(WindowLostFocusEvent& event) const
{
	Application::GetWindow()->CursorEnabled(true);
	return true;
}