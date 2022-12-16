import {makeAutoObservable} from "mobx";
import axios from "axios";

const url = 'http://localhost:18080/'

class Main{

    data=[]

    currentList =[]

    constructor() {
        makeAutoObservable(this)
    }

    async getData(){
        const response =  await axios.get(url)
        this.data = await response.data.data
    }

    async getListData(id){
        const response =  await axios.get(url+"add/"+id)
        this.currentList = await response.data.data
    }

    async DeleteListItem(id,index){
        await axios.delete(`${url}delete/${id}/${index}`)
        await this.getListData(id)
    }

    async sendTask(task,id){
        await axios({
            method: 'post',
            url: url + "add_json/" + id,
            headers: {
                'Content-Type' : 'text/plain'
            },
            data: {
                message: task, // This is the body part
            }
        });
        await this.getListData(id)
    }

}

export default new Main();