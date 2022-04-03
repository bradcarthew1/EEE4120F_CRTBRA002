//TODO: set your arguments for the kernel. Note that you have to indicate if the argument is global or local. Global arguments are accessable by both host and this target device. While local can only be accessed by the device running this kernel. eg __global int* inputMatrixA, __local int* groupMemory

__kernel void matrixMultiplication(__global int* matrixA, __global int* matrixB, __global int* output){
	
	//TODO: program your kernel here
	int workItemNum = get_global_id(0); //Work item ID
	int workGroupNum = get_group_id(0); //Work group ID
	int localGroupID = get_local_id(0); //Work items ID within each work group
	
	int Size = get_num_groups (0);
	int temp = 0;
	
	if (localGroupID == 0) {
		for (int j = 0; j<Size; j++) {
			for (int i = 0; i<Size; i++) {			
				temp = temp + matrixA[i+workGroupNum*Size]*matrixB[i*Size+j];
			}
			output[workGroupNum*Size+j] = temp;
			temp = 0;
		}
	}
}




