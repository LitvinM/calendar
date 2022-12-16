import './App.css';


import {observer} from 'mobx-react-lite'
import { Route } from "wouter";
import Main from "./pages/Main/main";
import List from "./pages/List/List";



function App() {


  return (
      <>
      <Route path="/" component={Main} />
          <Route path="/:id">
              {params => <List id={params.id} />}
          </Route>
      </>
  );
}

export default observer(App);
