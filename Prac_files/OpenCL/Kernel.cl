//TODO: set your arguments for the kernel. Note that you have to indicate if the argument is global or local. Global arguments are accessable by both host and this target device. While local can only be accessed by the device running this kernel. eg __global int* inputMatrixA, __local int* groupMemory

__kernel void matrixMultiplication(__global int* matrixA, __global int* matrixB, __global int* output){
	
	//TODO: program your kernel here
	int workItemNum = get_global_id(0); //Work item ID
	int workGroupNum = get_group_id(0); //Work group ID
	int localGroupID = get_local_id(0); //Work items ID within each work group
	
	int Size = get_num_groups (0); //get size of workgroup
	int temp = 0; //temp value to sum in matrix multiplicaiton
	
	if (localGroupID == 0) { //check if it is the first item in the work group
		for (int j = 0; j<Size; j++) {//iterate through matrices
			for (int i = 0; i<Size; i++) {//iterate through matrices
				temp = temp + matrixA[i+workGroupNum*Size]*matrixB[i*Size+j]; //sum multiplication of rows and columns
			}
			output[workGroupNum*Size+j] = temp; //send temp value to output matrix
			temp = 0; //set temp to 0 for next iteration
		}
	}
}




