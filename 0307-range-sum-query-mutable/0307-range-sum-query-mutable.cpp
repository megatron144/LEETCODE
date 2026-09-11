#define vi vector<int>

class SGT{
public:
    vi sg_tree;

    SGT(int n){
        sg_tree.resize(4*n+10);
    }

    void build(int idx,int l,int h,vi& v){
        if(l==h){
            sg_tree[idx]=v[l];
            return;
        }

        int mid=l+((h-l)>>1);

        build(idx*2+1,l,mid,v);
        build(idx*2+2,mid+1,h,v);

        sg_tree[idx]=sg_tree[2*idx+1]+sg_tree[2*idx+2];
    }

    int query(int idx,int l,int h,int L,int R){
        if(R<l || L>h)return 0;

        if(l>=L && h<=R)return sg_tree[idx];

        int mid=l+((h-l)>>1);

        int left=query(idx*2+1,l,mid,L,R);
        int right=query(idx*2+2,mid+1,h,L,R);

        return left+right;
    }

    void updateVal(int idx,int l,int h,int pos,int val){
        if(l==h){
            sg_tree[idx]=val;
            return;
        }

        int mid=l+((h-l)>>1);

        if(pos<=mid)
            updateVal(idx*2+1,l,mid,pos,val);
        else
            updateVal(idx*2+2,mid+1,h,pos,val);

        sg_tree[idx]=sg_tree[2*idx+1]+sg_tree[2*idx+2];
    }
};

class NumArray {
public:
    vector<int> v;
    int n;
    SGT* sg;

    NumArray(vector<int>& nums) {
        v=nums;
        n=v.size();

        sg=new SGT(n);
        sg->build(0,0,n-1,v);
    }

    void update(int index,int val) {
        sg->updateVal(0,0,n-1,index,val);
    }

    int sumRange(int left,int right) {
        return sg->query(0,0,n-1,left,right);
    }
};