import { Component, OnInit } from '@angular/core';
import {Data} from '../model/data';
import {Coin} from '../model/coin';
import {ComapiService} from '../comapi.service';
import {Router} from '@angular/router'

@Component({
  selector: 'app-recherche',
  templateUrl: './recherche.component.html',
  styleUrls: ['./recherche.component.css']
})
export class RechercheComponent implements OnInit {

  nomCrypto : String = "BITCOIN";
  
 listCrypto : Coin [];

onclick () {
    console.log ("Clique : " + this.nomCrypto );
    //this.listCrypto = this.comapi.getListCrypto ();

    this.comapi.getListCrypto().subscribe(d => {this.listCrypto = d.data; console.log(this.listCrypto);});
  }
  constructor(private comapi: ComapiService,private router: Router) { }

  ngOnInit() {
  }

}
