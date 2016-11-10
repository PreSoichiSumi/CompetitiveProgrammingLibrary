#include <climits>
#include <random>
//�����Z���k�E�c�C�X�^���������ȗ�������
//C++11�ȏ�
class xor128{
public:
    static constexpr unsigned min(){ return 0u; }   // �����̍ŏ��l
    static constexpr unsigned max(){ return UINT_MAX; } // �����̍ő�l
    unsigned operator()(){ return random(); }
    xor128();
    xor128(unsigned s){ w=s; }  // �^����ꂽ�V�[�h�ŏ�����
private:
    unsigned x=123456789u,y=362436069u,z=521288629u,w;
    unsigned random();
};
xor128::xor128(){
    // �V�[�h���^�����Ȃ����́A
    // �V�X�e���̃n�[�h�E�F�A�G���g���s�[�\�[�X����V�[�h�𐶐�
    std::random_device rd; 
    w=rd();

    for(int i=0;i<10;i++){  // �����ǂ�(�s�v?)
        random();
    }
}
unsigned xor128::random(){
    unsigned t;
    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}