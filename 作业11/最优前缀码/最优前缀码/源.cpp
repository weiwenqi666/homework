#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define n 8           //Ҷ����Ŀ
#define m 2*n-1       //���н������
typedef struct {       //�������
	double weight;    //����Ȩֵ
	int parent, lchild, rchild;//˫��ָ�뼰���Һ���
}HTNode;
typedef HTNode HuffmanTree[m];//HuffmanTree����������

typedef struct {       //����SelectMin����������Ľ������
	int id;           //���������������е����
	double weight;    //���������Ȩֵ
}temp;

typedef struct {       //������
	char ch;          //�洢�ַ�
	char bits[n + 1];   //��ű���λ��
}CodeNode;
typedef CodeNode HuffmanCode[n];

//��ʼ����������
void InitHuffmanTree(HuffmanTree T) {

	for (int i = 0; i < m; i++) {
		T[i].lchild = -1;
		T[i].rchild = -1;
		T[i].parent = -1;
		T[i].weight = 0;
	}
}

//����Ҷ��Ȩֵ
void InputWeight(HuffmanTree T) {
	for (int i = 0; i < n; i++) {//����n��Ҷ�ӵ�Ȩֵ����������ǰn��������
		double x;
		scanf_s("%lf", &x);
		T[i].weight = x;
	}
}
//��������ıȽϺ���
bool cmp(temp a, temp b) {
	return a.weight < b.weight;
}

//��ǰk�������ѡ��Ȩֵ��С�ʹ�С�ĸ���㣬����ŷֱ�Ϊp1��p2
void SelectMin(HuffmanTree T, int k, int* p1, int* p2) {
	temp x[m];              //x����Ϊtemp���͵�����
	int i, j;
	for (i = 0, j = 0; i <= k; i++) {  //Ѱ����С�ʹ�С���ڵ�Ĺ���
		if (T[i].parent == -1) {//����Ǹ��ڵ�,��������²���
			x[j].id = i;      //���ø��ڵ����Ÿ�ֵ��x
			x[j].weight = T[i].weight;//���ø��ڵ��Ȩֵ��ֵ��x
			j++;            //x������ָ�����һλ
		}
	}
	sort(x, x + j, cmp);        //��x����Ȩֵ��С��������
	//������x�����ĵ�һ�͵ڶ���λ���д洢��id�����ҵĸ��ڵ�����ֵ
	*p1 = x[0].id;
	*p2 = x[1].id;
}
//���ݹ�������T������������H
void CharSetHuffmanEncoding(HuffmanTree T, HuffmanCode H) {
	int c, p;//c��p�ֱ�ָʾT�к��Ӻ�˫�׵�λ��
	char cd[n + 1];//��ʱ��ű���
	int start;//ָʾ������cd�е���ʼλ��
	cd[n] = '\0';//���������
	getchar();
	for (int i = 0; i < n; i++) {//������Ҷ��T[i]�ı���
		H[i].ch = getchar();//����Ҷ��T[i]��Ӧ���ַ�
		start = n;//������ʼλ�õĳ�ֵ
		c = i;//��Ҷ��T[i]��ʼ����
		while ((p = T[c].parent) >= 0) {//ֱ�����ݵ�T[c]������Ϊֹ
			//��T[c]��T[p]�����ӣ������ɴ���0���������ɴ���1
			if (T[p].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
			c = p;//��������
		}
		strcpy_s(H[i].bits, &cd[start]);//���Ʊ���λ��
	}
}

void CreateHuffmanTree(HuffmanTree T) {
	//�������������T[m-1]Ϊ������
	int i, p1, p2;
	InitHuffmanTree(T);    //��T��ʼ��
	InputWeight(T);        //����Ҷ��Ȩֵ
	for (i = n; i < m; i++) {
		//�ڵ�ǰɭ��T[0����i-1]�����н���У�ѡȡȨ��С�ʹ�С��
		//���������T[p1]��T[p2]��Ϊ�ϲ�����
		//������n-1�κϲ����½�����δ���T[i]��

		SelectMin(T, i - 1, &p1, &p2);//ѡ��Ȩֵ��С�ʹ�С�ĸ���㣬����ŷֱ�Ϊp1��p2

		//����ΪT[p1]��T[p2]����������Ϊ���������ϲ�Ϊһ���µ���
		//�����ĸ����½��T[i]
		T[p1].parent = T[p2].parent = i;//T[p1]��T[p2]���������ĸ����ָ��i
		T[i].lchild = p1;             //��СȨ�ĸ�������½�������
		T[i].rchild = p2;             //��СȨ�ĸ�������½����Һ���
		T[i].weight = T[p1].weight + T[p2].weight;//�½���Ȩֵ������������Ȩֵ֮��
	}
}
int main() {
	HuffmanTree T;
	HuffmanCode H;
	printf("������%d��Ҷ�ӽ���Ȩֵ����������������\n", n);
	CreateHuffmanTree(T);
	printf("������%d��Ҷ�ӽ����������ַ���\n", n);
	CharSetHuffmanEncoding(T, H);
	printf("���������룺\n");
	for (int i = 0; i < n; i++) {
		printf("id:%d   ch:%c  code:%s\n", i, H[i].ch, H[i].bits);
	}
	return 0;
}
