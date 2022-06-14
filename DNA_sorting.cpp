






#include"iostream"
#include"string"

using namespace std;
typedef struct DNAdata {
    char name[51];
    int x;
    DNAdata() {
        x = 0;
    }
} DNAdata;

void SwapDNA(DNAdata* a, DNAdata* b) {
    DNAdata tempDNA;
    tempDNA = *a;
    *a = *b;
    *b = tempDNA;
}


void solution(int n, int m, DNAdata DNA[]) {
    char temp;
    for (int i = 0; i <m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> DNA[i].name[j];
        }
        for (int j = 0; j <n; j++)
        {
            temp = DNA[i].name[j];
            for (int k = j+1; k <n; k++)
            {
                if (temp> DNA[i].name[k])
                {
                    ++DNA[i].x;
                }
            }
        }
    }
    for (int i = 0; i !=m; i++) {
        for (int j = i; j > 0 && DNA[j - 1].x > DNA[j].x; --j) {
            SwapDNA(&DNA[j - 1], &DNA[j]);
        }
    }
    for (int i = 0; i <m; i++) {
        for (int j = 0; j <n; j++) {
            cout << DNA[i].name[j];
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    DNAdata DNA[101];
    cin >> n >> m;
    solution(n, m, DNA);
}