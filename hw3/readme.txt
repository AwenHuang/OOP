1.�Ǹ� : 400410048
2.�m�W : ������
3.email : jokeygeek@gmail.com
4.�}�o����: �t�W�u�@��(csie0.cs.ccu.edu.tw)
5.�ާ@���� : �N�{�������T�����A<hw3.h><hw3.cpp><main.cpp>
------------------------------------------------------
�Q��isfinite()���^�ǭ�[true,false]�h�P�_�ײv�O�_�L���j(�ײv���s�b),�Y�b�ײvfunction����return -1�h�|�X��,�]���ײv���i��O��-1,�G�Φ��禡�h���ײv���P�_
<makefile>

	��Jmake => �sĶ.h�ɥH�νsĶ���.cpp�ɥͦ�hw3������
	��Jmake clear => �M��hw3������
<hw3.h>
	�N�|�Ӫ���(Line�BLine2�BCircle�BCircle2)�إ߰_�ӡA�ä��O�إߥL�̪��ݩ����O(private�Bpublic)�����ܼƥH�Ψ禡�C
	�Q��friend�ŧi�����ݩ�class���禡�i�H����class��private�������C

<hw3.cpp> �Nclass���w�q��function�A��ԲӤ��e���b���ɮסC
	
	�C��class������constructor�h�]�ߪ�l��,EX:Line::Line()
	�C��class�����h�����J���禡�A��KŪ����J�A�M�h�L�X�ڭ̷Q�n����X����
	
	��Line�\��禡²�满��:
		�Q�Φh�����l�h�L�Xy=ax+b�A�קK��(�ײv���s�B�ײv���s�b�Bb=0�����p)�A�h²�ƦL�X�����l

		1.slope: 
			�^��(y1-y0)/(x1-x0)�A�o��ӽu�ײv�A�Y�ײv���s�b�h�L�X"slope does not exit".
		2.y_intercept:
			�^��y0 - (((y1-y0)/(x1-x0))*x0),�o��ӽu��y�I�Z�A�Yy�I�Z���t�ƫh�b��(-1)�ϥL�����ơC
			�p�G�ײv���s�b�hy�I�Z�]���s�b�A�^��-1�A�L�X"y_intercept does not exit"
		3.vshift:
			�ǤJ�ϥΪ̭nshift���ܶq�A�M����y0�My1�[�W���ܶq�C

	��Line2�\��禡²�满��:
		�Q�Φh�����l�h�L�Xy=ax+b�A�קK��(�ײv���s�B�ײv���s�b�Bb=0�����p)�A�h²�ƦL�X�����l
		�]��line2�O�ǤJ�@���I�H�Ψ�Ӥ�V�V�q(dx,dy)�Gline2���ײv�i�H��dy/dx�Ӻ�X

		1.normal:
			�]�����u�ײv�M�k�u�ײv����(�ۭ���-1)�A�G�k�u�ײv��dx/dy*(-1)�A�Q��isinf()�P�_�ײv�O�_�s�b�A�M��L�X�ӽu

	��Circle�\��禡²�满��
		�Q�Φh�����l�h�L�X(x-cx)^2+(y-cy)^2=r^2�A�קK��(cx�Mcy�i�ର�s�����p�Mcxcy�i�ର�t�ƪ����p�A)�A�h²�ƦL�X�����l
		���p�G�ϥΪ̿�J�b�|���t�Ʃιs�h�^��Circle manu		
		1.radius:
			�^�Ƕꪺ�b�|�C
		2.set_center:
			�ǤJ�ϥΪ̭n���ܪ���ߡA�M�᪽���N�s��x�My����class����cx�Mcy
		3.is_inside:
			�ǤJ�@���I�A�Q�θ��I�M��ߪ��Z���h�M�ꪺ�b�l������A�p�G�Z����b�|�j�h���I���b�ꤺ�A�p�G�Z����b�|�p�ε���b�|�A�h���I�b�ꤺ�A�L�Xyes or no

	��Circle2�\��禡²�满��
		�Q�Φh�����l�h�L�X(x-cx)^2+(y-cy)^2=r^2�A�קK��(cx�Mcy�i�ର�s�����p�Mcxcy�i�ର�t�ƪ����p�A)�A�h²�ƦL�X�����l

		�]��Circle2�O��J��Ӧb��W���I(�Y���I�Z�������|)�A�G�������Q�Φ��S�ʺ�X�b�|�M���(���I���I)�A�A�h���MCircle�@�˪��P�_�M��X

		1.is_inside:
			�]��Circle2�O��J��Ӧb��W���I(�Y���I�Z�������|)�A�G�������Q�Φ��S�ʺ�X�b�|�M���(���I���I)
			�ǤJ�@���I�A�Q�θ��I�M��ߪ��Z���h�M�ꪺ�b�l������A�p�G�Z����b�|�j�h���I���b�ꤺ�A�p�G�Z����b�|�p�ε���b�|�A�h���I�b�ꤺ�A�L�Xyes or no



<main.cpp>

�ϥΪ̤����H�Υ\��P�w���b���ɤ����C

�ھڨϥΪ̿�ܪ����O�A�A�h�߰ݭn�ϥθ����O��إ\��A����back�ﶵ�A���ϥΪ̥i�H�^��D�����A�h��ܨ�L���O�C




	