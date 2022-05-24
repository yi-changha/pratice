using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LifeCycle : MonoBehaviour
{
    void Awake()    // ���� ������Ʈ ������ ��, ���� ����
    {
        Debug.Log("�÷��̾� �����Ͱ� �غ�Ǿ����ϴ�.");
    }

    void OnEnable() // ���� ������Ʈ�� Ȱ��ȭ �Ǿ��� ��
    {
        Debug.Log("�÷��̾ �α����߽��ϴ�.");
    }

    void Start()    // ������Ʈ ���� ����, ���� ����
    {
        Debug.Log("��� ��� ì����ϴ�.");
    }

    void FixedUpdate()  // ���� ���� ������Ʈ (������ ���� �ֱ�� CPU�� ���� ���)
    {
        Debug.Log("�̵�");
    }

    void Update()   // ���� ���� ������Ʈ (ȯ�濡 ���� ���� �ֱⰡ ������ �� ����)
    {
        Debug.Log("���� ���");
    }

    void LateUpdate()   // ��� ������Ʈ�� ���� ��
    {
        Debug.Log("����ġ ȹ��");
    }

    void OnDisable()    // ���� ������Ʈ�� ��Ȱ��ȭ �Ǿ��� ��
    {
        Debug.Log("�÷��̾ �α׾ƿ� �߽��ϴ�.");
    }

    void OnDestroy()    // ���� ������Ʈ�� ������ ��
    {
        Debug.Log("�÷��̾� �����͸� �����Ͽ����ϴ�.");
    }
}
